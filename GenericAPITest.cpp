#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include "Actor.h"
#include "Director.h"
#include "Genre.h"
#include "JellenReview.h"
#include "Movie.h"
#include "Personnel.h"
#include "GenericAPI.h"
#include <map>


using namespace std;
using namespace crow;

map<std::string, Actor> actorsMap;
map<std::string, Director> directorsMap;
map<std::string, Genre> genresMap;
map<std::string, JellenReview> reviewsMap;
map<std::string, Movie> moviesMap;
map<std::string, Personnel> personnelMap;

TEST_CASE("Creating a new Actor resource") 
{
    // Setup resource map to be empty before the test
    GenericAPI<Actor>::resourceMap.clear();

    // Setup request object
    request req;
    req.body = R"({"canImprov":true,"id":"1","name":"Zac Efron"})"; 

    // Perform the action
    response res = GenericAPI<Actor>::createResource(req);

    // Check the results
    CHECK(res.code == 201); // Check that the response code is 201 Created
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(GenericAPI<Actor>::resourceMap.size() == 1); // Ensure the resource was added to the map
    CHECK(GenericAPI<Actor>::resourceMap.at("1").getID() == "1"); // Validate the resource content
    CHECK(GenericAPI<Actor>::resourceMap.at("1").getName() == "Zac Efron"); // Validate the resource content
    CHECK(GenericAPI<Actor>::resourceMap.at("1").getImprov() == true); // Validate the resource content
}

TEST_CASE("Reading an Actor resource") 
{
    // Load a resource to read.
    actorsMap["1"] = Actor{json::load(R"({"canImprov":true,"id":"1","name":"Zac Efron"})")};

    // Setup resource map to be empty before the test
    GenericAPI<Actor>::resourceMap = actorsMap;

    // Perform the action
    response res = GenericAPI<Actor>::readResource("1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == actorsMap["1"].convertToJson().dump()); // Validate the reponse body
    CHECK(GenericAPI<Actor>::resourceMap.size() == 1); // Ensure that no resources were added or removed from the map
}

TEST_CASE("Reading all Actor resources") 
{
    // Load resources to read.
    actorsMap["1"] = Actor{json::load(R"({"canImprov":true,"id":"1","name":"Zac Efron"})")};
    actorsMap["2"] = Actor{json::load(R"({"canImprov":false,"id":"2","name":"Vanessa Hudgens"})")};
    actorsMap["3"] = Actor{json::load(R"({"canImprov": true,"id":"3","name":"Ashley Tisdale"})")};
    actorsMap["4"] = Actor{json::load(R"({"canImprov":false,"id":"4","name":"Corbin Bleu"})")};

    // Setup resource map to be empty before the test
    GenericAPI<Actor>::resourceMap = actorsMap;

    // Perform the action
    response res = GenericAPI<Actor>::readAllResources();

    // Create the expected reponse body
    string expectedResponseBody = R"([{"canImprov":true,"id":"1","name":"Zac Efron"},{"name":"Vanessa Hudgens","id":"2","canImprov":false},{"canImprov":true,"id":"3","name":"Ashley Tisdale"},{"canImprov":false,"id":"4","name":"Corbin Bleu"}])";

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == expectedResponseBody); // Validate the reponse body
    CHECK(GenericAPI<Actor>::resourceMap.size() == 4); // Ensure that no resources were added or removed from the map
}


TEST_CASE("Updating an Actor resource") 
{
    // Load resources to update.
    actorsMap["1"] = Actor{json::load(R"({"canImprov":true,"id":"1","name":"Zac Efron"})")};
    actorsMap["2"] = Actor{json::load(R"({"canImprov":false,"id":"2","name":"Vanessa Hudgens"})")};
    actorsMap["3"] = Actor{json::load(R"({"canImprov": true,"id":"3","name":"Ashley Tisdale"})")};
    actorsMap["4"] = Actor{json::load(R"({"canImprov":false,"id":"4","name":"Corbin Bleu"})")};

    // Setup resource map to be empty before the test
    GenericAPI<Actor>::resourceMap = actorsMap;

    // Setup request object
    request req;
    req.body = R"({"canImprov":true,"id":"1","name":"Monique Coleman"})"; 

    // Setup a response object
    response res;

    // Perform the action
    GenericAPI<Actor>::updateResource(req, res, "1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(GenericAPI<Actor>::resourceMap.size() == 4); // Ensure no resource was added or removed from the map
    CHECK(GenericAPI<Actor>::resourceMap.at("1").getID() == "1"); // Validate the resource content
    CHECK(GenericAPI<Actor>::resourceMap.at("1").getName() == "Monique Coleman"); // Validate the resource content
    CHECK(GenericAPI<Actor>::resourceMap.at("1").getImprov() == true); // Validate the resource content
}


TEST_CASE("Deleting an Actor resource") 
{
    // Load a resources to update.
    actorsMap["1"] = Actor{json::load(R"({"canImprov":true,"id":"1","name":"Zac Efron"})")};
    actorsMap["2"] = Actor{json::load(R"({"canImprov":false,"id":"2","name":"Vanessa Hudgens"})")};
    actorsMap["3"] = Actor{json::load(R"({"canImprov": true,"id":"3","name":"Ashley Tisdale"})")};
    actorsMap["4"] = Actor{json::load(R"({"canImprov":false,"id":"4","name":"Corbin Bleu"})")};

    // Setup resource map to be empty before the test
    GenericAPI<Actor>::resourceMap = actorsMap;

    // Perform the action
    response res = GenericAPI<Actor>::deleteResource("4");

    // Check the results
    CHECK(res.code == 204); // Check that the response code is 204 No Content
    CHECK(res.body == ""); // Validate the reponse body
    CHECK(GenericAPI<Actor>::resourceMap.size() == 3); // Ensure one resource was removed from the map
}
