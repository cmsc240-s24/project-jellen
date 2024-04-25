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
    json::wvalue writeJson = Personnel::convertToJson();

    writeJson["number of films made"] = numberOfFilmsMade;
    return writeJson;
}

// Update from JSON
void Director::updateFromJson(json::rvalue readValueJson) 
{
    Personnel::updateFromJson(readValueJson);
    
    numberOfFilmsMade = readValueJson["number of films made"].();
}