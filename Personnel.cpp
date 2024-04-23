#include "Personnel.h"

using namespace std;
using namespace crow;

Personnel::Personnel(json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Personnel::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = personnelID;
    writeJson["name"] = personnelName;
    return writeJson;
}

// Update from JSON
void Personnel::updateFromJson(json::rvalue readValueJson) 
{
    personnelID = readValueJson["id"].s();
    personnelName = readValueJson["name"].s();
}