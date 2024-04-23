#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "Actor.h"

using namespace std;  
using namespace crow;  

TEST_CASE("Testing Actor Class") 
{
    // Testing Actor constructor
    SUBCASE("Testing the Actor Constructor") 
    {
        // Create a new Actor class from json.
        Actor testActor(json::load(R"({"actor":"Zendaya","id":"1"})"));

        // Check that the constructor properly loaded the values.
        CHECK(testActor.getActorID() == "1");
        CHECK(testActor.getActor() == "Zendaya");
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Actor class from json.
        Actor testActor(json::load(R"({"actor":"Zendaya","id":"1"})"));

        // Convert the Actor class to json using the convertToJson method.
        json::wvalue jsonOutput = testActor.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        CHECK(jsonReadValue["actor"].s() == "Zendaya");
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Actor class from json.
        Actor testActor(json::load(R"({"actor":"Zendaya","id":"1"})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"actor":"Adam Sandler","id":"2"})");

        // Update the Actor with the updateFromJson method. 
        testActor.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testActor.getGenreID() == "2");
        CHECK(testActor.getGenre() == "Adam Sandler");
    }
}