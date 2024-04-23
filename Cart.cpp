#include "Cart.h"

using namespace std;
using namespace crow;

Cart::Cart(json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Cart::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = cartID;
    writeJson["movies"] = movies;
    writeJson["amount owed"] = amount;
    return writeJson;
}

// Update from JSON
void Genre::updateFromJson(json::rvalue readValueJson) 
{
    cartID = readValueJson["id"].s();
    movies = readValueJson["movies"].s();
    amount = readValueJson["amount owed"].s();
}