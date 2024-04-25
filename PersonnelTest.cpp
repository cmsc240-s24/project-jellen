#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "Personnel.h"

using namespace std;  
using namespace crow;  

TEST_CASE("Testing Personnel Class") 
{
    // Testing Personnel constructor
    SUBCASE("Testing the Personnel Constructor") 
    {
        // Create a new Personnel class from json.
        Personnel testPersonnel(json::load(R"({"name":"Wes Anderson","id":"1")"));

        // Check that the constructor properly loaded the values.
        CHECK(testPersonnel.getID() == "1");
        CHECK(testPersonnel.getName() == "Wes Anderson");
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Personnel class from json.
        Personnel testPersonnel(json::load(R"({"name":"Wes Anderson","id":"1"})"));

        // Convert the Personnel class to json using the convertToJson method.
        json::wvalue jsonOutput = testPersonnel.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        CHECK(jsonReadValue["name"].s() == "Wes Anderson");
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Personnel class from json.
        Personnel testPersonnel(json::load(R"({"name":"Wes Anderson","id":"1"})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"name":"Kenny Ortega","id":"2"})");

        // Update the Personnel with the updateFromJson method. 
        testPersonnel.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testPersonnel.getID() == "2");
        CHECK(testPersonnel.getName() == "Kenny Ortega");    }
}