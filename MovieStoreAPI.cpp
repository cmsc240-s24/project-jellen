#include <crow.h>
#include <map>
#include <csignal>
#include <string>
#include "Actor.h"
#include "Director.h"
#include "Genre.h"
#include "JellenReview.h"
#include "Movie.h"
#include "GenericAPI.h"
#include "persistence.h"

using namespace std;
using namespace crow;

// Load resources from files.
map<std::string, Actor> actorsMap = loadFromFile<Actor>("actors.json");
map<std::string, Director> directorsMap = loadFromFile<Director>("directors.json");
map<std::string, Genre> genresMap = loadFromFile<Genre>("genres.json");
map<std::string, JellenReview> reviewsMap = loadFromFile<JellenReview>("reviews.json");
map<std::string, Movie> moviesMap = loadFromFile<Movie>("movies.json");
map<std::string, Personnel> personnelMap = loadFromFile<Personnel>("personnel.json");

int main() 
{
    // Create GenericAPIs to use in the CROW_ROUTES
    GenericAPI<Actor>::resourceMap = actorsMap;
    GenericAPI<Director>::resourceMap = directorsMap;
    GenericAPI<Genre>::resourceMap = genresMap;
    GenericAPI<JellenReview>::resourceMap = reviewsMap;
    GenericAPI<Movie>::resourceMap = moviesMap;
    GenericAPI<Personnel>::resourceMap = personnelMap;

    // Setup the simple web service.
    SimpleApp app;

    // Define resources:
    // Actor
    CROW_ROUTE(app, "/api/actors").methods("POST"_method)(GenericAPI<Actor>::createResource);
    CROW_ROUTE(app, "/api/actors").methods("GET"_method)(GenericAPI<Actor>::readAllResources);
    CROW_ROUTE(app, "/api/actors/<string>").methods("GET"_method)(GenericAPI<Actor>::readResource);
    CROW_ROUTE(app, "/api/actors/<string>").methods("PUT"_method)(GenericAPI<Actor>::updateResource);
    CROW_ROUTE(app, "/api/actors/<string>").methods("DELETE"_method)(GenericAPI<Actor>::deleteResource);

    // Director
    CROW_ROUTE(app, "/api/directors").methods("POST"_method)(GenericAPI<Director>::createResource);
    CROW_ROUTE(app, "/api/directors").methods("GET"_method)(GenericAPI<Director>::readAllResources);
    CROW_ROUTE(app, "/api/directors/<string>").methods("GET"_method)(GenericAPI<Director>::readResource);
    CROW_ROUTE(app, "/api/directors/<string>").methods("PUT"_method)(GenericAPI<Director>::updateResource);
    CROW_ROUTE(app, "/api/directors/<string>").methods("DELETE"_method)(GenericAPI<Director>::deleteResource);
    
    // Genre
    CROW_ROUTE(app, "/api/genres").methods("POST"_method)(GenericAPI<Genre>::createResource);
    CROW_ROUTE(app, "/api/genres").methods("GET"_method)(GenericAPI<Genre>::readAllResources);
    CROW_ROUTE(app, "/api/genres/<string>").methods("GET"_method)(GenericAPI<Genre>::readResource);
    CROW_ROUTE(app, "/api/genres/<string>").methods("PUT"_method)(GenericAPI<Genre>::updateResource);
    CROW_ROUTE(app, "/api/genres/<string>").methods("DELETE"_method)(GenericAPI<Genre>::deleteResource);

    // JellenReview
    CROW_ROUTE(app, "/api/reviews").methods("POST"_method)(GenericAPI<JellenReview>::createResource);
    CROW_ROUTE(app, "/api/reviews").methods("GET"_method)(GenericAPI<JellenReview>::readAllResources);
    CROW_ROUTE(app, "/api/reviews/<string>").methods("GET"_method)(GenericAPI<JellenReview>::readResource);
    CROW_ROUTE(app, "/api/reviews/<string>").methods("PUT"_method)(GenericAPI<JellenReview>::updateResource);
    CROW_ROUTE(app, "/api/reviews/<string>").methods("DELETE"_method)(GenericAPI<JellenReview>::deleteResource);
    // Movie
    CROW_ROUTE(app, "/api/movies").methods("POST"_method)(GenericAPI<Movie>::createResource);
    CROW_ROUTE(app, "/api/movies").methods("GET"_method)(GenericAPI<Movie>::readAllResources);
    CROW_ROUTE(app, "/api/movies/<string>").methods("GET"_method)(GenericAPI<Movie>::readResource);
    CROW_ROUTE(app, "/api/movies/<string>").methods("PUT"_method)(GenericAPI<Movie>::updateResource);
    CROW_ROUTE(app, "/api/movies/<string>").methods("DELETE"_method)(GenericAPI<Movie>::deleteResource);

    // Personnel
    CROW_ROUTE(app, "/api/personnel").methods("POST"_method)(GenericAPI<Personnel>::createResource);
    CROW_ROUTE(app, "/api/personnel").methods("GET"_method)(GenericAPI<Personnel>::readAllResources);
    CROW_ROUTE(app, "/api/personnel/<string>").methods("GET"_method)(GenericAPI<Personnel>::readResource);
    CROW_ROUTE(app, "/api/personnel/<string>").methods("PUT"_method)(GenericAPI<Personnel>::updateResource);
    CROW_ROUTE(app, "/api/personnel/<string>").methods("DELETE"_method)(GenericAPI<Personnel>::deleteResource);
    
    // Run the web service app.
    app.port(17892).run();
        
    // After the web service stops running:

    // Perform persistence of resources
    saveToFile<Actor>(GenericAPI<Actor>::resourceMap, "actors.json");
    saveToFile<Director>(GenericAPI<Director>::resourceMap, "directors.json");
    saveToFile<Genre>(GenericAPI<Genre>::resourceMap, "genres.json");
    saveToFile<JellenReview>(GenericAPI<JellenReview>::resourceMap, "reviews.json");
    saveToFile<Movie>(GenericAPI<Movie>::resourceMap, "movies.json");
    saveToFile<Personnel>(GenericAPI<Personnel>::resourceMap, "personnel.json");
}
