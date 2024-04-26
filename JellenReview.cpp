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
    setID(jellenReviewID = readValueJson["id"].s());
    setReview(reviewString = readValueJson["review"].s());
    setRating(jellenRating = readValueJson["rating"].i());
    setWouldWatchAgain(wouldWatchAgain = readValueJson["would watch again"].b());
}
