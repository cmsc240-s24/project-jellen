#include "Cart.h"

using namespace std;
using namespace crow;
extern map<std::string, Movie> moviesMap;

Cart::Cart(json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Cart::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = cartID;

    int index = 0;
    for (Movie movie : movies) 
    {
        writeJson["movies"][index]["id"] = movie.getId();
    }
   
    writeJson["amount owed"] = amount;
    
    return writeJson;
}

// Update from JSON
void Cart::updateFromJson(json::rvalue readValueJson) 
{
    cartID = readValueJson["id"].s();

    // Setting movies
    for (json::rvalue movieReadValueJson: readValueJson["movies"])
    {
        movies.push_back(moviesMap.at(movieReadValueJson["id"].s()));
    }
    
    amount = readValueJson["amount owed"].();
}