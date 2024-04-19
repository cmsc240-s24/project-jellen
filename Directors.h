#ifndef DIRECTORS_H
#define DIRECTORS_H

class Directors 
{
    public:
        /**
         * @brief Constructs a new Directors object.
         * @param id the Directors ID.
         * @param name the Directors name.
         * @param filmsMade the number of films made.
         */
        Directors(std::string id, std::string name, int filmsMade);

        /**
         * @brief Returns the id of Directors.
         * @return id of Directors.
         */
        std::string getID() const { return directorID; }

        /**
         * @brief Sets the value of directorID.
         * @param newID the Directors ID.
         */
        void setID(std::string newID) { directorID = newID; }

        /**
         * @brief Returns the name of Directors.
         * @return name of Directors.
         */
        std::string getName() const { return directorName; }

        /**
         * @brief Sets the value of directorName.
         * @param newName the Directors name.
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
         * @brief Convert the Directors object to JSON
         * @return crow::json::wvalue
         */ 
        crow::json::wvalue convertToJson();

        /**
         * @brief Update the Directors object from JSON
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

#endif // DIRECTORS_H