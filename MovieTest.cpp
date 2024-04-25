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

        // Create a new Movie class from json.
        Movie testMovie(json::load(R"({"id":"1","title":"Schindler's List","cost":3.99,"length": 195, "linkToMoviePoster":
        "https://www.imdb.com/title/tt0108052/mediaviewer/rm1610023168/?ref_=tt_ov_i","personnel":[{"id": "1"}],"genre":{"id":"1"}, "review":{"id":"1"}})"));

        // Check that the constructor properly loaded the values.
        CHECK(testMovie.getID() == "1");
        CHECK(testMovie.getTitle() == "Schindler's List");
        CHECK(testMovie.getCost() == 3.99);
        CHECK(testMovie.getLength() == 195);
        CHECK(testMovie.getGenre().getID() == "1");
        CHECK(testMovie.getPersonnel()[0].getID() == "1");
        CHECK(testMovie.getReview().getID() == "1");
        CHECK(testMovie.getPoster() == "https://www.imdb.com/title/tt0108052/mediaviewer/rm1610023168/?ref_=tt_ov_i");

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
        Movie testMovie(json::load(R"({"id":"1","title":"Schindler's List","cost":3.99,"length": 195, "linkToMoviePoster":
        "https://www.imdb.com/title/tt0108052/mediaviewer/rm1610023168/?ref_=tt_ov_i","personnel":[{"id": "1"}],"genre":{"id":"1"}, "review":{"id":"1"}})"));
}
        // Create the update json.
        json::rvalue updateJson = json::load(R"({"id":"1","title":"Fight Club","cost":3.99,"length": 139, "linkToMoviePoster":
        "https://www.imdb.com/title/tt0137523/mediaviewer/rm1412004864/?ref_=tt_ov_i","personnel":[{"id": "1"}],"genre":{"id":"1"}, "review":{"id":"1"}})");

        // Update the Movie with the updateFromJson method. 
        testMovie.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testMovie.getID() == "1");
        CHECK(testMovie.getTitle() == "Fight Club");
        CHECK(testMovie.getCost() == 3.99);
        CHECK(testMovie.getLength() == 139);
        CHECK(testMovie.getGenre().getID() == "1");
        CHECK(testMovie.getPersonnel()[0].getID() == "1");
        CHECK(testMovie.getReview().getID() == "1");
        CHECK(testMovie.getPoster() == "https://www.imdb.com/title/tt0137523/mediaviewer/rm1412004864/?ref_=tt_ov_i");
    }
}