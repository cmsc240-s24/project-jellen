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
        Actor testActor(json::load(R"({"name":"Zendaya","id":"1","canImprov":true})"));

        // Check that the constructor properly loaded the values.
        CHECK(testActor.getID() == "1");
        CHECK(testActor.getName() == "Zendaya");
        CHECK(testActor.getImprov() == true);
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Actor class from json.
        Actor testActor(json::load(R"({"name":"Zendaya","id":"1", "canImprov":true})"));

        // Convert the Actor class to json using the convertToJson method.
        json::wvalue jsonOutput = testActor.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        CHECK(jsonReadValue["name"].s() == "Zendaya");
        CHECK(testActor.getImprov() == true);
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Actor class from json.
        Actor testActor(json::load(R"({"name":"Zendaya","id":"1","canImprov":true})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"name":"Adam Sandler","id":"2","canImprov":true})");

        // Update the Actor with the updateFromJson method. 
        testActor.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testActor.getID() == "2");
        CHECK(testActor.getName() == "Adam Sandler");
        CHECK(testActor.getImprov() == true);
    }
}