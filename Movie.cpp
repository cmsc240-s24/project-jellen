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
    writeJson["genre"] = movieGenre;
    writeJson["personnel"] = moviePersonnel;
    writeJson["linktoMoviePoster"] = linktoMoviePoster;
    
    // Convert artists to json (Save only the ids)
    int index = 0;
    for (Artist artist : artists) 
    {
        writeJson["artists"][index]["id"] = artist.getId();
    }

    // // If you want the full json for each artist to be included:
    // for (Artist artist : artists) 
    // {
    //     writeJson["artists"] = artist.convertToJson();
    // }

    // Convert genre to json (Save only the id)
    writeJson["genre"]["id"] = genre.getId();
 
    return writeJson;
}

// Update from JSON
void Album::updateFromJson(json::rvalue readValueJson) 
{
    id = readValueJson["id"].s();
    title = readValueJson["title"].s();
    cost = readValueJson["cost"].d();
    mediaType = readValueJson["mediaType"].s();
    linkToCoverArt = readValueJson["linkToCoverArt"].s();
    
    // Setting artists
    for (json::rvalue artistReadValueJson: readValueJson["artists"])
    {
        artists.push_back(artistsMap.at(artistReadValueJson["id"].s()));
    }

    // Setting genre
    json::rvalue genreReadValueJson = readValueJson["genre"];
    genre = genresMap.at(genreReadValueJson["id"].s());
}