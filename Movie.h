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

#include <crow.h>
#include <string>
#include "JellenReview.h"
#include "Genre.h"
#include "Personnel.h"

/**
 * @class Movie
 * @brief Movie class
 *
 * This Movie class holds information about the movie
 * including its ID, title, length, genre, personnel, and movie poster.
 */
class Movie
{
    public:
        /**
         * @brief default constructor: Movie
         */
        Movie() {};
        
        /**
         * @brief Construct a new Movie object
         * @param readValueJson
         */
        Movie(crow::json::rvalue readValueJson);
        
        /**
         * @brief Returns the id of Movie.
         * @return id of Movie.
         */
        std::string getID() const { return movieID; }

        /**
         * @brief Sets the value of movieID.
         * @param newID the Movie ID.
         */
        void setID(std::string newID) { movieID = newID; }

        /**
         * @brief Returns the title of the movie.
         * @return title of movie.
         */
        std::string getTitle() const { return movieTitle; }

        /**
         * @brief Sets the title of the movie.
         * @param newTitle title of movie.
         */
        void setTitle(std::string newTitle) { movieTitle = newTitle; }

        /**
         * @brief Returns the cost of the movie.
         * @return cost of movie.
         */
        double getCost() const { return movieCost; }

        /**
         * @brief Sets the cost of the movie.
         * @param newCost cost of movie.
         */
        void setCost(double newCost) { movieCost = newCost; }

        /**
         * @brief Returns the length of the movie.
         * @return length of movie.
         */
        int getLength() const { return movieLength; }

        /**
         * @brief Sets the length of the movie.
         * @param newLength length of movie.
         */
        void setLength(int newLength) { movieLength = newLength; }

        /**
         * @brief Returns the Genre of the movie.
         * @return Genre of movie.
         */
        Genre getGenre() const { return movieGenre; }

        /**
         * @brief Sets the Genre of the movie.
         * @param newGenre genre of movie.
         */
        void setGenre(Genre newGenre) { movieGenre = newGenre; }

        /**
         * @brief Returns the personnel of the movie.
         * @return personnel of movie.
         */
        std::vector<Personnel> getPersonnel() const { return moviePersonnel; }

        /**
         * @brief Sets the personnel of the movie.
         * @param newPersonnel personnel of movie.
         */
        void setPersonnel(std::vector<Personnel> newPersonnel) { moviePersonnel = newPersonnel; }

        /**
         * @brief Returns the link to the poster of the movie.
         * @return movie poster.
         */
        std::string getPoster() const { return linkToMoviePoster; }

        /**
         * @brief Sets the link to the poster of the movie.
         * @param newPoster new poster link for movie.
         */
        void setPoster(std::string newPoster) { linkToMoviePoster = newPoster; }

        /**
         * @brief Convert the Movie object to JSON
         * @return crow::json::wvalue
         */
        void updateFromJson(crow::json::rvalue readValueJson);
        
        /**
         * @brief Convert the Movie object to JSON
         * @return crow::json::wvalue
         */
        crow::json::wvalue convertToJson();

    private: 
        /**
         * @brief movieID
         */
        std::string movieID;

        /**
         * @brief movieTitle
         */
        std::string movieTitle;

        /**
         * @brief movieCost
         */
        double movieCost;

        /**
         * @brief movieLength
         */
        int movieLength;

        /**
         * @brief movieGenre
         */
        Genre movieGenre;

        /**
         * @brief moviePersonnel
         */
        std::vector<Personnel> moviePersonnel;

        /**
         * @brief movieReview
         */
        JellenReview movieReview;

        /**
         * @brief linkToMoviePoster
        */
        std::string linkToMoviePoster;
};

#endif // MOVIE_H