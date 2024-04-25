// Director.h
/**
 * @file Director.h
 * @brief Header file for the Director class.
 *
 * This file contains the declaration of the Director class along with its
 * member functions and variables.
 */

#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <crow.h>
#include <string>
#include "Personnel.h"

/**
 * @class Director
 * @brief Director class
 *
 * This Director class holds information about the director of
 * the movie including their ID, name, and number of films made.
 * */
class Director : public Personnel
{
    public:
        /**
         * @brief default constructor: Director
         */
        Director() {};
        
        /**
         * @brief Construct a new Director object
         * @param readValueJson
         */
        Director(crow::json::rvalue readValueJson);

        /**
         * @brief Returns the number of films made by the director.
         * @return number of films made by the director.
         */
        int getFilmsMade() const { return numberOfFilmsMade; }

        /**
         * @brief Sets the value of the number of films made by the director.
         * @param newFilmsMade the number of films made by the director.
         */
        void setFilmsMade(int newFilmsMade) { numberOfFilmsMade = newFilmsMade; }

        /**
         * @brief Convert the Director object to JSON
         * @return crow::json::wvalue
         */ 
        crow::json::wvalue convertToJson();

        /**
         * @brief Update the Director object from JSON
         * @param readValueJson the JSON object to update from.
         */
        void updateFromJson(crow::json::rvalue readValueJson);
   
    private:
        /**
         * @brief numberOfFilmsMade
        */
        int numberOfFilmsMade;
};

#endif // DIRECTOR_H