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
    writeJson["genreID"] = genreID;
    writeJson["genre"] = genre;
    return writeJson;
}

// Update from JSON
void Genre::updateFromJson(json::rvalue readValueJson) 
{
    genreID = readValueJson["genreID"].s();
    genre = readValueJson["genre"].s();
}