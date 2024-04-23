// Genre.h
/**
 * @file Genre.h
 * @brief Header file for the Genre class.
 *
 * This file contains the declaration of the Genre class along with its
 * member functions and variables.
 */

#ifndef GENRE_H
#define GENRE_H

#include <crow.h>
#include <string>

/**
 * @class Genre
 * @brief Genre class
 *
 * This Genre class holds information about the genre of
 * the movie including its ID and genre.
 */
class Genre
{
    public:
        /**
         * @brief default constructor: Genre
         */
        Genre() {};
        
        /**
         * @brief Construct a new Genre object
         * @param readValueJson
         */
        Genre(crow::json::rvalue readValueJson);

        /**
         * @brief Get the Genre ID object
         * @return string genreID
         */
        std::string getGenreID() const { return genreID; }

        /**
         * @brief Get the Genre object
         * @return std::string genre
         */
        std::string getGenre() const { return genre; }

        /**
         * @brief Set the Genre ID object
         * @param genreID
         */
        void setGenreID(std::string idParam) { genreID = idParam; }

        /**
         * @brief Set the Genre object
         * @param genre
         */
        void setGenre(std::string genreParam) { genre = genreParam; }

        /**
         * @brief Convert the Genre object to JSON
         * @return crow::json::wvalue JSON object
         */
        crow::json::wvalue convertToJson();

        /**
         * @brief Update the Genre object from JSON
         * @param readValueJson
         */
        void updateFromJson(crow::json::rvalue readValueJson);

    private:
        /**
         * @brief Genre ID
         */
        std::string genreID;

        /**
         * @brief Genre
         */
        std::string genre;
};

#endif // GENRE_H