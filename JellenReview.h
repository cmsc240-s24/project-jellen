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
         * @brief Constructs a new JellenReview object.
         * @param id the id of the JellenReview.
         * @param review the review of the movie.
         * @param rating the rating of the movie.
         * @param again if Jellen would watch the movie again.
         */
        JellenReview(std::string id, std::string review, int rating, bool again);
        
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
         * @brief Returns Jellen's rating of the movie.
         * @return Jellen's rating of the movie.
         */
        int getRating() { return rating; }

        /**
         * @brief Sets the value of rating.
         * @param newRating Jellen's rating of movie.
         */
        void setRating(int newRating) { rating = newRating; }

        // !!!
        // do get movie & set movie once that .h file has been made

        /**
         * @brief Returns the value of if Jellen would rewatch the movie.
         * @return true if Jellen would watch the movie again, false if not.
         */
        bool getWouldWatchAgain() { return wouldWatchAgain; }

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
        std::string jellenReviewID;
        std::string reviewString;
        int jellenRating;
        bool wouldWatchAgain;
};

#endif // JELLEN_REVIEW_H