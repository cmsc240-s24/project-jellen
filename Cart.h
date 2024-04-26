// Cart.h
/**
 * @file Cart.h
 * @brief Header file for the Cart class.
 *
 * This file contains the declaration of the Cart class  along with its
 * member functions and variables.
 */

#ifndef CART_H
#define CART_H

#include <crow.h>
#include <string>
#include <vector>
#include "Movie.h"

/**
 * @class Cart
 * @brief Cart class
 *
 * This Cart class holds information about the cart of
 * the user including its ID and movies.
*/
class Cart
{
    public:
        /**
         * @brief default constructor: Cart
         */
        Cart() {};
            
        /**
         * @brief Construct a new Cart object
         * @param readValueJson
         */
        Cart(crow::json::rvalue readValueJson);

        /**
         * @brief Get the Cart ID object
         * @return std::string
         */
        std::string getID() const { return cartID; }

        /**
         * @brief Get the Movies object
         * @return std::vector<Movies>
         */
     
        std::vector<Movie> getMovies() const { return movies; }

        /**
         * @brief Set the Cart ID object
         * @param cartID
        */
        void setID(std::string idParam) { cartID = idParam; }

        /**
         * @brief Set the Movies object
         * @param movies
         */
        void setMovies(std::vector<Movie> moviesParam) { movies = moviesParam; }

        /**
         * @brief Convert the Cart object to JSON
         * @return crow::json::wvalue
        */
        crow::json::wvalue convertToJson();

        /**
         * @brief Update the Cart object from JSON
         * @param readValueJson
         */
        void updateFromJson(crow::json::rvalue readValueJson);

    private:
        /**
         * @brief Cart ID
         */
        std::string cartID;

        /**
         * @brief Movies
         */
        std::vector<Movie> movies;

        /**
         * @brief amount
         */
        double amount;

};

#endif // CART_H
