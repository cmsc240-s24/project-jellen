#ifndef ACTORS_H
#define ACTORS_H

#include "Person.h"
#include <string>
#include <crow.h>

class Actors
{
    public:
        /**
         * @brief Constructs a new Actors object.
         * @param id the Actors ID.
         * @param name the Actors name.
         * @param improv if the actor can improv.
         */
        Actors(std::string id, std::string name, bool improv);

        /**
         * @brief Returns the id of Actors.
         * @return id of Actors.
         */
        std::string getID() const { return actorID; }

        /**
         * @brief Sets the value of actorID.
         * @param newID the Actors ID.
         */
        void setID(std::string newID) { actorID = newID; }

        /**
         * @brief Returns the name of Actors.
         * @return name of Actors.
         */
        std::string getName() const { return actorName; }

        /**
         * @brief Sets the value of actorName.
         * @param newName the Actors name.
         */
        void setName(std::string newName) { actorName = newName; }

        /**
         * @brief Returns the value of if the actor can improv.
         * @return true if the actor can improv, false if not.
         */
        bool getImprov() { return canImprov; }

        /**
         * @brief Sets the value of if the actor can improv.
         * @param newImprov if the actor can improv.
         */
        void setImprov(bool newImprov) { canImprov = newImprov; }

        /**
         * @brief Convert the Actors object to JSON
         * @return crow::json::wvalue
         */ 
        crow::json::wvalue convertToJson();

        /**
         * @brief Update the Actors object from JSON
         * @param readValueJson
         */
        void updateFromJson(crow::json::rvalue readValueJson);
        
    private:
        /**
         * @brief Actor ID
        */
        std::string actorID;

        /**
         * @brief Actor Name
        */
        std::string actorName;

        /**
         * @brief canImprov
        */
        bool canImprov;
};

#endif