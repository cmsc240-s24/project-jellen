// Personnel.h
/**
 * @file Personnel.h
 * @brief Header file for the Personnel class.
 *
 * This file contains the declaration of the Personnel class along with its
 * member functions and variables.
 */

#include PERSONNEL_H
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
         * @brief Constructs a new Personnel object.
         * @param id the id of the Personnel.
         * @param name the name of the Personnel.
         */
        Personnel(std::string id, std::string name);
        
        /**
         * @brief Returns the id of Personnel.
         * @return id of Personnel.
         */
        std::string getID() const { return personnelID; }

        /**
         * @brief Sets the value of personnelID.
         * @param newID the Personnel ID.
         */
        void setID(std::string newID) { personnelID = newID; }

        /**
         * @brief Returns the name of Personnel.
         * @return name of Personnel.
         */
        std::string getName() const { return personnelName; }

        /**
         * @brief Sets the value of personnelName.
         * @param newName the Personnel name.
         */
        void setName(std::string newName) { personnelName = newName; }

        /**
         * @brief Convert the Personnel object to JSON
         * @return crow::json::wvalue
         */
        updateFromJson(crow::json::rvalue readValueJson);
        
        /**
         * @brief Convert the Cart object to JSON
         * @return crow::json::wvalue
         */
        crow::json::wvalue convertToJson();

    private:
        /**
         * @brief Personnel ID
         */
        std::string personnelID;

        /**
         * @brief Personnel Name
         */
        std::string personnelName;
};

#endif // PERSONNEL_H