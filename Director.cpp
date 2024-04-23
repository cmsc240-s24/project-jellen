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
    writeJson["directorID"] = directorID;
    writeJson["directorName"] = directorName;
    writeJson["numberOfFilmsMade"] = numberOfFilmsMade;
    return writeJson;
}

// Update from JSON
void Director::updateFromJson(json::rvalue readValueJson) 
{
    directorID = readValueJson["directorID"].s();
    directorName = readValueJson["directorName"].s();
    numberOfFilmsMade = readValueJson["numberOfFilmsMade"].s();
}