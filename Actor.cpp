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
    json::wvalue writeJson;
    writeJson["id"] = actorID;
    writeJson["name"] = actorName;
    writeJson["canImprov"] = canImprov;
    return writeJson;
}

// Update from JSON
void Actor::updateFromJson(json::rvalue readValueJson) 
{
    actorID = readValueJson["id"].s();
    actorName = readValueJson["name"].s();
    canImprov = readValueJson["canImprov"].b();
}