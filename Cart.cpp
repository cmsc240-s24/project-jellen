#include "Cart.h"

using namespace std;
using namespace crow;

Cart(std::string id, std::vector<Movie> moviesList);

Cart::Cart(json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Cart::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["cartID"] = cartID;
    writeJson["movies"] = movies;
    return writeJson;
}

// Update from JSON
void Genre::updateFromJson(json::rvalue readValueJson) 
{
    cartID = readValueJson["cartID"].s();
    movies = readValueJson["movies"].s();
}