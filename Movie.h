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
         * @brief Constructs a new Movie object.
         * @param id the id of the movie
         * @param title the title of the movie
         * @param length the length of the movie
         * @param genre the genre of the movie
         * @param personnelList the personnel involved in the creation of the movie
         * @param poster the link to the poster of the movie
         */
        Movie(std::string id, std::string title, double length, Genre genre, std::vector<Personnel> personnelList, std::string poster);
        
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
        std::string getTitle() { return movieTitle; }

        /**
         * @brief Sets the title of the movie.
         * @param newTitle title of movie.
         */
        void setTitle(std::string newTitle) { movieTitle = newTitle; }

        /**
         * @brief Returns the length of the movie.
         * @return length of movie.
         */
        double getLength() { return movieLength; }

        /**
         * @brief Sets the length of the movie.
         * @param newLength length of movie.
         */
        void setLength(std::string newLength) { movieLength = newLength; }

        /**
         * @brief Returns the Genre of the movie.
         * @return Genre of movie.
         */
        Genre getGenre() { return movieGenre; }

        /**
         * @brief Sets the Genre of the movie.
         * @param newGenre genre of movie.
         */
        void setGenre(Genre newGenre) { movieGenre = newGenre; }

        /**
         * @brief Returns the personnel of the movie.
         * @return personnel of movie.
         */
        std::vector<Personnel> getPersonnel() { return moviePersonnel; }

        /**
         * @brief Sets the personnel of the movie.
         * @param newPersonnel personnel of movie.
         */
        void setPersonnel(std::vector<Personnel> newPersonnel) { moviePersonnel = newPersonnel; }

        /**
         * @brief Returns the link to the poster of the movie.
         * @return movie poster.
         */
        std::string getPoster() { return linkToMoviePoster; }

        /**
         * @brief Sets the link to the poster of the movie.
         * @param newPoster new poster link for movie.
         */
        void setTitle(std::string newPoster) { linkToMoviePoster = newPoster; }

        /**
         * @brief Convert the Movie object to JSON
         * @return crow::json::wvalue
         */
        updateFromJson(crow::json::rvalue readValueJson);
        
        /**
         * @brief Convert the Movie object to JSON
         * @return crow::json::wvalue
         */
        crow::json::wvalue convertToJson();

    private: 
        std::string movieID;
        std::string movieTitle;
        double movieLength;
        Genre movieGenre;
        std::vector<Personnel> moviePersonnel;
        std::string linkToMoviePoster;
};

#endif // MOVIE_H