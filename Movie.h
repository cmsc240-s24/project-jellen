// Movie.h
/**
 * @file Movie.h
 * @brief Header file for the Movie class.
 *
 * This file contains the declaration of the Movie class along with its
 * member functions and variables.
 */
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "JellenReview.h"
#include "Genre.h"

/**
 * @class Movie
 * @brief A class that offers Movie activity.
 *
 * This class can perform actions such as...
 */
class Movie
{
public:
    /**
     * @brief Constructs a new Movie object.
     * @param 
     * @param 
     */
    JellenReview(std::string id, std::string review, int rating, bool wouldWatchAgain);
    
    /**
     * @brief Returns the id of JellenReview.
     * @return id of JellenReview.
     */
    std::string getID() const { return jellenReviewID; }

     /**
     * @brief Sets the value of jellenReviewID.
     * @param newRating the JellenReview ID.
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
    std::string movieID;
    std::string title;
    double length;
    Genre movieGenre;
    std::vector<Director> directors;
    std::string linkToMoviePoster;
};

#endif // MOVIE_H