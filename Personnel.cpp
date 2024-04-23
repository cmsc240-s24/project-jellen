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
    writeJson["personnelID"] = personnelID;
    writeJson["personnelName"] = personnelName;
    return writeJson;
}

// Update from JSON
void Personnel::updateFromJson(json::rvalue readValueJson) 
{
    personnelID = readValueJson["personnelID"].s();
    personnelName = readValueJson["personnelName"].s();
}