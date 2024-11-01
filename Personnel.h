// Personnel.h
/**
 * @file Personnel.h
 * @brief Header file for the Personnel class.
 *
 * This file contains the declaration of the Personnel class along with its
 * member functions and variables.
 */
#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <crow.h>
#include <string>

/**
 * @class Personnel
 * @brief Personnel class
 *
 * This Personnel class holds information about the personnel involved in the creation of
 * the movie including their ID and name.
 */
class Personnel 
{
    public:
       /**
         * @brief default constructor: Personnel
         */
        Personnel() {};
        
        /**
         * @brief Construct a new Personnel object
         * @param readValueJson
         */
        Personnel(crow::json::rvalue readValueJson);
        
        /**
         * @brief Returns the id of Personnel.
         * @return id of Personnel.
         */
        std::string getID() const { return id; }

        /**
         * @brief Sets the value of id.
         * @param newID the Personnel ID.
         */
        void setID(std::string newID) { id = newID; }

        /**
         * @brief Returns the name of Personnel.
         * @return name of Personnel.
         */
        std::string getName() const { return name; }

        /**
         * @brief Sets the value of name.
         * @param newName the Personnel name.
         */
        void setName(std::string newName) { name = newName; }

        /**
         * @brief Convert the Personnel object to JSON
         * @return crow::json::wvalue
         */ 
        crow::json::wvalue convertToJson();

        /**
         * @brief Convert the Personnel object to JSON
         * @return crow::json::wvalue
         */
        void updateFromJson(crow::json::rvalue readValueJson);

    private:
        /**
         * @brief Personnel ID
         */
        std::string id;

        /**
         * @brief Personnel Name
         */
        std::string name;
};

#endif // PERSONNEL_H