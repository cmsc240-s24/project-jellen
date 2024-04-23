#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "Director.h"

using namespace std;  
using namespace crow;  

TEST_CASE("Testing Director Class") 
{
    // Testing Director constructor
    SUBCASE("Testing the Genre Constructor") 
    {
        // Create a new Director class from json.
        Director testDirector(json::load(R"({"director":"Wes Anderson","id":"1"})"));

        // Check that the constructor properly loaded the values.
        CHECK(testDirector.getDirectorID() == "1");
        CHECK(testDirector.getDirector() == "Wes Anderson");
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Director class from json.
        Director testDirector(json::load(R"({"director":"Wes Anderson","id":"1"})"));

        // Convert the Director class to json using the convertToJson method.
        json::wvalue jsonOutput = testDirector.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        CHECK(jsonReadValue["director"].s() == "Wes Anderson");
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Director class from json.
        Director testDirector(json::load(R"({"director":"Wes Anderson","id":"1"})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"director":"Kenny Ortega","id":"2"})");

        // Update the Director with the updateFromJson method. 
        testDirector.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testDirector.getDirectorID() == "2");
        CHECK(testDirector.getDirector() == "Kenny Ortega");
    }
}