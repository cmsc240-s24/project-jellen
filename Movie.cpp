#include "Movie.h"

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
    movieID = readValueJson["id"].s();
    movieTitle = readValueJson["title"].s();
    movieCost = readValueJson["cost"].d();
    movieLength = readValueJson["length"].d();
    linktoMoviePoster = readValueJson["linkToMoviePoster"].s();

    // Setting Personnel
    for (json::rvalue personnelReadValueJson: readValueJson["personnel"])
    {
        moviePersonnel.push_back(personnelMap.at(personnelReadValueJson["id"].s()));
    }

    // Setting Genre
    json::rvalue genreReadValueJson = readValueJson["genre"];
    genre = genresMap.at(genreReadValueJson["id"].s());

    // Setting JellenReview
    json::rvalue reviewReadValueJson = readValueJson["review"];
    review = reviewsMap.at(reviewReadValueJson["id"].s());
}