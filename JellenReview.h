// JellenReview.h
/**
 * @file JellenReview.h
 * @brief Header file for the Jellen Review class.
 *
 * This file contains the declaration of the Jellen Review class along with its
 * member functions and variables.
 */

#ifndef JELLENREVIEW_H
#define JELLENREVIEW_H

#include <crow.h>
#include <string>

/**
 * @class JellenReview
 * @brief JellenReview class
 *
 * This JellenReview class holds information about Jellen's reviews of
 * a movie including its ID, the review itself, the rating, and if Jellen would watch it again.
 */
class JellenReview
{
    public:
        /**
         * @brief default constructor: JellenReview
         */
        JellenReview() {};
        
        /**
         * @brief Construct a new JellenReview object
         * @param readValueJson
         */
        JellenReview(crow::json::rvalue readValueJson);
        
        /**
         * @brief Returns the id of JellenReview.
         * @return id of JellenReview.
         */
        std::string getID() const { return jellenReviewID; }

        /**
         * @brief Sets the value of jellenReviewID.
         * @param newID the JellenReview ID.
         */
        void setID(std::string newID) { jellenReviewID = newID; }

        /**
         * @brief Returns Jellen's review of the movie.
         * @return Jellen's review of the movie.
         */
        std::string getReview() const { return reviewString; }

        /**
         * @brief Sets the value of review.
         * @param newReview Jellen's review of movie.
         */
        void setReview(std::string newReview) { reviewString = newReview; }

        /**
         * @brief Returns Jellen's rating of the movie.
         * @return Jellen's rating of the movie.
         */
        int getRating() const { return jellenRating; }

        /**
         * @brief Sets the value of rating.
         * @param newRating Jellen's rating of movie.
         */
        void setRating(int newRating) { jellenRating = newRating; }

        /**
         * @brief Returns the value of if Jellen would rewatch the movie.
         * @return true if Jellen would watch the movie again, false if not.
         */
        bool getWouldWatchAgain() const { return wouldWatchAgain; }

        /**
         * @brief Sets the value of if Jellen would rewatch the movie.
         * @param newWouldWatchAgain if Jellen would watch the movie again.
         */
        void setWouldWatchAgain(bool newWouldWatchAgain) { wouldWatchAgain = newWouldWatchAgain;}

        /**
         * @brief Convert the JellenReview object to JSON
         * @return crow::json::wvalue
         */ 
        crow::json::wvalue convertToJson();

        /**
         * @brief Update the JellenReview object from JSON
         * @param readValueJson the JSON object to update from.
         */
        void updateFromJson(crow::json::rvalue readValueJson);
   

    private: 
        /**
         * @brief Jellen Review ID
         */
        std::string jellenReviewID;

        /**
         * @brief review
         */
        std::string reviewString;

        /**
         * @brief rating
         */
        int jellenRating;

        /**
         * @brief would watch again
         */
        bool wouldWatchAgain;
};

#endif // JELLEN_REVIEW_H
