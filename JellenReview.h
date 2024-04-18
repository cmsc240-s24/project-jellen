// JellenReview.h
/**
 * @file JellenReview.h
 * @brief Header file for the Jellen Review class.
 *
 * This file contains the declaration of the Jellen Review class along with its
 * member functions and variables.
 */
#ifndef JELLEN_REVIEW_H
#define JELLEN_REVIEW_H

#include <string>

/**
 * @class JellenReview
 * @brief A class that offers jellen review activity.
 *
 * This class can perform actions such as set/get ratings, set/get
 * reviews, and get/set if jellen would watch it again.
 */
class JellenReview
{
public:
    /**
     * @brief Constructs a new JellenReview object.
     * @param jellenReviewID the id of the JellenReview.
     * @param review the review of the movie.
     * @param rating the rating of the movie.
     * @param wouldWatchAgain if Jellen would watch the movie again.
     */
    JellenReview(std::string jellenReviewID, std::string review, int rating, bool wouldWatchAgain);
    
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

private: 
    std::string jellenReviewID;
    std::string review;
    int rating;
    bool wouldWatchAgain;
};

#endif // JELLEN_REVIEW_H