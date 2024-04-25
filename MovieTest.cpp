#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "Movie.h"

using namespace std;  
using namespace crow;  

TEST_CASE("Testing Movie Class") 
{
    // Testing Movie constructor
    SUBCASE("Testing the Movie Constructor") 
    {
        Genre horror(json::load(R"({"id":"1","genre":"Historical Drama"})))
        

        // Create a new Movie class from json.
        Movie testMovie(json::load(R"({"id":"1","title":"Schindler's List","cost":3.99,"length": 195, "linkToMoviePoster":
        "https://www.imdb.com/title/tt0108052/mediaviewer/rm1610023168/?ref_=tt_ov_i","personnel":[{}],"genre":})"));

        // Check that the constructor properly loaded the values.
        CHECK(testMovie.getID() == "1");
        CHECK(testMovie.getName() == "Zendaya");
        CHECK(testMovie.getImprov() == true);
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Movie class from json.
        Movie testMovie(json::load(R"({"name":"Zendaya","id":"1", "canImprov":true})"));

        // Convert the Movie class to json using the convertToJson method.
        json::wvalue jsonOutput = testMovie.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        CHECK(jsonReadValue["name"].s() == "Zendaya");
        CHECK(testMovie.getImprov() == true);
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Movie class from json.
        Movie testMovie(json::load(R"({"name":"Zendaya","id":"1","canImprov":true})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"name":"Adam Sandler","id":"2","canImprov":true})");

        // Update the Movie with the updateFromJson method. 
        testMovie.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testMovie.getID() == "2");
        CHECK(testMovie.getName() == "Adam Sandler");
        CHECK(testMovie.getImprov() == true);
    }
}