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
    writeJson["actorID"] = actorID;
    writeJson["actorName"] = actorName;
    writeJson["canImprov"] = canImprov;
    return writeJson;
}

// Update from JSON
void Actor::updateFromJson(json::rvalue readValueJson) 
{
    actorID = readValueJson["actorID"].s();
    actorName = readValueJson["actorName"].s();
    canImprov = readValueJson["canImprov"].s();
}