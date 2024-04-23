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
         * @brief Constructs a new Director object.
         * @param id the Director ID.
         * @param name the Director name.
         * @param filmsMade the number of films made.
         */
        Director(std::string id, std::string name, int filmsMade);

        /**
         * @brief Returns the id of Director.
         * @return id of Director.
         */
        std::string getID() const { return directorID; }

        /**
         * @brief Sets the value of directorID.
         * @param newID the Director ID.
         */
        void setID(std::string newID) { directorID = newID; }

        /**
         * @brief Returns the name of Director.
         * @return name of Director.
         */
        std::string getName() const { return directorName; }

        /**
         * @brief Sets the value of directorName.
         * @param newName the Director name.
         */
        void setName(std::string newName) { directorName = newName; }

        /**
         * @brief Returns the number of films made by the director.
         * @return number of films made by the director.
         */
        int getFilmsMade() { return numberOfFilmsMade; }

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
         * @brief directorID
        */
        std::string directorID;

        /**
         * @brief directorName
        */
        std::string directorName;

        /**
         * @brief numberOfFilmsMade
        */
        int numberOfFilmsMade;
};

#endif // DIRECTOR_H