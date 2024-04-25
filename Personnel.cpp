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
    writeJson["id"] = id;
    writeJson["name"] = name;
    return writeJson;
}

// Update from JSON
void Personnel::updateFromJson(json::rvalue readValueJson) 
{
    id = readValueJson["id"].s();
    name = readValueJson["name"].s();
}