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
        JellenReview testJellenReview(json::load(R"({"id":"1","review":"'High School Musical' is a feel-good teen musical that charms audiences 
with its catchy songs and uplifting storyline. With its infectious energy and relatable characters, it's a fun ride for fans of musicals and high school dramas alike.","rating":7,
"would watch again":true})"));

        // Check that the constructor properly loaded the values.
        CHECK(testJellenReview.getID() == "1");
        CHECK(testJellenReview.getReview() == "'High School Musical' is a feel-good teen musical that charms audiences 
with its catchy songs and uplifting storyline. With its infectious energy and relatable characters, it's a fun ride for fans of musicals and high school dramas alike.");
        CHECK(testJellenReview.getRating() == 7);
        CHECK(testJellenReview.getWouldWatchAgain() == true);
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new JellenReview class from json.
        JellenReview testJellenReview(json::load(R"({"id":"1","review":"'High School Musical' is a feel-good teen musical that charms audiences 
with its catchy songs and uplifting storyline. With its infectious energy and relatable characters, it's a fun ride for fans of musicals and high school dramas alike.","rating":7,
"would watch again":true})"));

        // Convert the JellenReview class to json using the convertToJson method.
        json::wvalue jsonOutput = testJellenReview.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        CHECK(jsonReadValue["review"].s() == "'High School Musical' is a feel-good teen musical that charms audiences 
with its catchy songs and uplifting storyline. With its infectious energy and relatable characters, it's a fun ride for fans of musicals and high school dramas alike.");
        CHECK(jsonReadValue["rating"].i() == 7);
        CHECK(jsonReadValue["would watch again"].b() == true);
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new JellenReview class from json.
        JellenReview testJellenReview(json::load(R"({"id":"1","review":"'High School Musical' is a feel-good teen musical that charms audiences 
with its catchy songs and uplifting storyline. With its infectious energy and relatable characters, it's a fun ride for fans of musicals and high school dramas alike.","rating":7,
"would watch again":true})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"id":"1","review":"'Good Will Hunting' is a poignant drama that explores themes of intellect, identity, 
        and friendship with powerful performances from its cast. Matt Damon and Robin Williams shine in this emotionally resonant tale of self-discovery and second chances.",
        "rating":9,"would watch again":true})");

        // Update the Director with the updateFromJson method. 
        testJellenReview.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testJellenReview.getID() == "1");
        CHECK(testJellenReview.getReview() == "'Good Will Hunting' is a poignant drama that explores themes of intellect, identity, 
        and friendship with powerful performances from its cast. Matt Damon and Robin Williams shine in this emotionally resonant tale of self-discovery and second chances.");
        CHECK(testJellenReview.getRating() == 9);
        CHECK(testJellenReview.getWouldWatchAgain() == true);
    }
}