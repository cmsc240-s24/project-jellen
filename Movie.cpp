#include "Movie.h"
#include <map>
#include "Genre.h" 
#include "JellenReview.h" 
#include "Personnel.h"
#include "GenericAPI.h"

using namespace std;
using namespace crow;

extern map<std::string, Genre> genresMap;
extern map<std::string, JellenReview> reviewsMap;
extern map<std::string, Personnel> personnelMap;

Movie::Movie(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Movie::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = movieID;
    writeJson["title"] = movieTitle;
    writeJson["cost"] = movieCost;
    writeJson["length"] = movieLength;
    writeJson["linkToMoviePoster"] = linkToMoviePoster;
    
    // Convert personnel to json (Save only the ids)
    int index = 0;
    for (Personnel person : moviePersonnel) 
    {
        writeJson["personnel"][index]["id"] = person.getID();
    }
    writeJson["genre"]["id"] = movieGenre.getID();
    writeJson["review"]["id"] = movieReview.getID();

    return writeJson;
}

// Update from JSON
void Movie::updateFromJson(json::rvalue readValueJson) 
{
    setID(movieID = readValueJson["id"].s());
    setTitle(movieTitle = readValueJson["title"].s());
    setCost(movieCost = readValueJson["cost"].d());
    setLength(movieLength = readValueJson["length"].i());
    setPoster(linkToMoviePoster = readValueJson["linkToMoviePoster"].s());

    // Setting Personnel
    for (json::rvalue personnelReadValueJson: readValueJson["personnel"])
    {
        moviePersonnel.push_back(personnelMap.at(personnelReadValueJson["id"].s()));
    }

    // Setting Genre
    json::rvalue genreReadValueJson = readValueJson["genre"];
    movieGenre = genresMap.at(genreReadValueJson["id"].s());

    // Setting JellenReview
    json::rvalue reviewReadValueJson = readValueJson["review"];
    movieReview = reviewsMap.at(reviewReadValueJson["id"].s());
}
