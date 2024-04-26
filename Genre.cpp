#include "Genre.h"

using namespace std;
using namespace crow;


Genre::Genre(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Genre::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = genreID;
    writeJson["genre"] = genre;
    return writeJson;
}

// Update from JSON
void Genre::updateFromJson(json::rvalue readValueJson) 
{
    setID(genreID = readValueJson["id"].s());
    setGenre(genre = readValueJson["genre"].s());
}
