#include "Director.h"

using namespace std;
using namespace crow;

Director::Director(json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Director::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = directorID;
    writeJson["name"] = directorName;
    writeJson["number of films made"] = numberOfFilmsMade;
    return writeJson;
}

// Update from JSON
void Director::updateFromJson(json::rvalue readValueJson) 
{
    directorID = readValueJson["id"].s();
    directorName = readValueJson["name"].s();
    numberOfFilmsMade = readValueJson["number of films made"].s();
}