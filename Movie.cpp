#include "Movie.h"

using namespace std;
using namespace crow;

extern map<std::string, Genre> genresMap;
extern map<std::string, Artist> artistsMap;

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
    writeJson["genre"]["id"] = movieGenre.getGenreID();
    writeJson["review"]["id"] = movieReview.getID();
    writeJson["linktoMoviePoster"] = linktoMoviePoster;
    
    // Convert personnel to json (Save only the ids)
    int index = 0;
    for (Personnel person : moviePersonnel) 
    {
        writeJson["personnel"][index]["id"] = person.getID();
    }
    return writeJson;
}

// Update from JSON
void Album::updateFromJson(json::rvalue readValueJson) 
{
    movieID = readValueJson["id"].s();
    movieTitle = readValueJson["title"].s();
    movieCost = readValueJson["cost"].s();
    movieLength = readValueJson["length"].s();
    linktoMoviePoster = readValueJson["linkToMoviePoster"].s();
    // Setting artists
    for (json::rvalue artistReadValueJson: readValueJson["artists"])
    {
        artists.push_back(artistsMap.at(artistReadValueJson["id"].s()));
    }

    // Setting genre
    json::rvalue genreReadValueJson = readValueJson["genre"];
    genre = genresMap.at(genreReadValueJson["id"].s());
}