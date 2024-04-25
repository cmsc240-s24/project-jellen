#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "JellenReview.h"

using namespace std;  
using namespace crow;  

TEST_CASE("Testing JellenReview Class") 
{
    // Testing JellenReview constructor
    SUBCASE("Testing the JellenReview Constructor") 
    {
        // Create a new JellenReview class from json.
        JellenReview testDirector(json::load(R"({"id":"1","review":"","rating":11})"));

        // Check that the constructor properly loaded the values.
        CHECK(testDirector.getID() == "1");
        CHECK(testDirector.getName() == "Wes Anderson");
        CHECK(testDirector.getFilmsMade() == 11);
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Director class from json.
        Director testDirector(json::load(R"({"name":"Wes Anderson","id":"1","number of films made":11})"));

        // Convert the Director class to json using the convertToJson method.
        json::wvalue jsonOutput = testDirector.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        CHECK(jsonReadValue["name"].s() == "Wes Anderson");
        CHECK(jsonReadValue["number of films made"].i() == 11);
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new JellenReview class from json.
        JellenReview testDirector(json::load(R"({"name":"Wes Anderson","id":"1","number of films made":11})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"name":"Kenny Ortega","id":"2","number of films made":7})");

        // Update the Director with the updateFromJson method. 
        testDirector.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testDirector.getID() == "2");
        CHECK(testDirector.getName() == "Kenny Ortega");
        CHECK(testDirector.getFilmsMade() == 7);
    }
}