#include <crow.h>
#include <doctest.h>
#include <string>
#include "Cart.h"

using namespace std;
using namespace crow;

TEST_CASE("Testing Cart Class") 
{
    // Testing Cart constructor
    SUBCASE("Testing the Cart Constructor") 
    {
        // Create a new Cart class from json.
        Cart testCart(json::load(R"({"cartID":"1","movies":[{"id":"1","title":"The Grand Budapest Hotel","director":"Wes Anderson"},{"id":"2","title":"Soul","director":"Director2"}]})"));

        // Check that the constructor properly loaded the values.
        CHECK(testCart.getCartID() == "1");
        CHECK(testCart.getMovies().size() == 2);
        CHECK(testCart.getMovies()[0].getTitle() == "The Grand Budapest Hotel");
        CHECK(testCart.getMovies()[1].getTitle() == "Soul");
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Cart class from json.
        Cart testCart(json::load(R"({"cartID":"1","movies":[{"id":"1","title":"The Grand Budapest Hotel","director":"Wes Anderson"},{"id":"2","title":"Soul","director":"Director2"}]})"));

        // Convert the Cart class to json using the convertToJson method.
        json::wvalue jsonOutput = testCart.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["cartID"].s() == "1");
        CHECK(jsonReadValue["movies"].size() == 2);
        CHECK(jsonReadValue["movies"][0]["title"].s() == "The Grand Budapest Hotel");
        CHECK(jsonReadValue["movies"][1]["title"].s() == "Soul");
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Cart class from json.
        Cart testCart(json::load(R"({"cartID":"1","movies":[{"id":"1","title":"The Grand Budapest Hotel","director":"Wes Anderson"},{"id":"2","title":"Soul","director":"Director2"}]})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"cartID":"2","movies":[{"id":"3","title":"Whiplash","director":"Damien Chazelle"},{"id":"4","title":"The Cheetah Girls 2","director":"Kenny Ortega"}]})");

        // Update the Cart with the updateFromJson method. 
        testCart.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testCart.getCartID() == "2");
        CHECK(testCart.getMovies().size() == 2);
        CHECK(testCart.getMovies()[0].getTitle() == "Whiplash");
        CHECK(testCart.getMovies()[1].getTitle() == "The Cheetah Girls 2");
    }
}
