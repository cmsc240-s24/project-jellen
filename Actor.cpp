#include "Actor.h"

using namespace std;
using namespace crow;

Actor::Actor(json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Actor::convertToJson() 
{
    json::wvalue writeJson = Personnel::convertToJson();

    writeJson["canImprov"] = canImprov;

    return writeJson;
}

// Update from JSON
void Actor::updateFromJson(json::rvalue readValueJson) 
{
    Personnel::updateFromJson(readValueJson);
    canImprov = readValueJson["canImprov"].b();
}