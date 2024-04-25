#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include "Genre.h"
#include "persistence.h"

using namespace std;
using namespace crow;


TEST_CASE("Saving to a file and loading from a file.") 
{
    // Load a resources to read.
    map<string, Genre> genresMap;
    genresMap["1"] = Genre{json::load(R"({"genre":"Horror","id":"1"})")};
    genresMap["2"] = Genre{json::load(R"({"genre":"Action","id":"2"})")};
    genresMap["3"] = Genre{json::load(R"({"genre":"Comedy","id":"3"})")};
    genresMap["4"] = Genre{json::load(R"({"genre":"Thriller","id":"4"})")};

    // Perform the action
    saveToFile<Genre>(genresMap, "persistenceTest.json");
    map<string, Genre> genresMapLoaded = loadFromFile<Genre>("persistenceTest.json");

    // Check the results
    CHECK(genresMap.size() == genresMapLoaded.size()); // Ensure saved and loaded map are the same size.
    CHECK(genresMap.at("1").getID() == genresMapLoaded.at("1").getID()); // Validate the resource content
    CHECK(genresMap.at("1").getGenre() == genresMapLoaded.at("1").getGenre()); // Validate the resource content
    CHECK(genresMap.at("2").getID() == genresMapLoaded.at("2").getID()); // Validate the resource content
    CHECK(genresMap.at("2").getGenre() == genresMapLoaded.at("2").getGenre()); // Validate the resource content
    CHECK(genresMap.at("3").getID() == genresMapLoaded.at("3").getID()); // Validate the resource content
    CHECK(genresMap.at("3").getGenre() == genresMapLoaded.at("3").getGenre()); // Validate the resource content
    CHECK(genresMap.at("4").getID() == genresMapLoaded.at("4").getID()); // Validate the resource content
    CHECK(genresMap.at("4").getGenre() == genresMapLoaded.at("4").getGenre()); // Validate the resource content
}