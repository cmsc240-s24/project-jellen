#include PERSONNEL_H
#define PERSONNEL_H

#include <string>

/**
 * @class Personnel
 * @brief A class that offers Personnel activity.
 *
 * This class can perform actions such as...
 */
class Personnel 
{
    public:
        /**
         * @brief Constructs a new Personnel object.
         * @param personnelID the id of the Personnel.
         * @param personnelName the name of the Personnel.
         */
        Personnel(std::string personnelID, std::string personnelName);
        
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
         *
         * @return crow::json::wvalue
         
        */
        updateFromJson(crow::json::rvalue readValueJson);
        
        /**
         * @brief Convert the Cart object to JSON
         *
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