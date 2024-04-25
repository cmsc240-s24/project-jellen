#include "JellenReview.h"

using namespace std;
using namespace crow;

JellenReview::JellenReview(json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue JellenReview::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = jellenReviewID;
    writeJson["review"] = reviewString;
    writeJson["rating"] = jellenRating;
    writeJson["would watch again"] = wouldWatchAgain;
    return writeJson;
}

// Update from JSON
void JellenReview::updateFromJson(json::rvalue readValueJson) 
{
    jellenReviewID = readValueJson["id"].s();
    reviewString = readValueJson["review"].s();
    jellenRating = readValueJson["rating"].i();
    wouldWatchAgain = readValueJson["would watch again"].b();
}