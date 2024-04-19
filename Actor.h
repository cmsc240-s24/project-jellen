// Actor.h
/**
 * @file Actor.h
 * @brief Header file for the Actor class.
 *
 * This file contains the declaration of the Actor class along with its
 * member functions and variables.
 */

#ifndef ACTOR_H
#define ACTOR_H

#include "Personnel.h"
#include <string>
#include <crow.h>

/**
 * @class Actor
 * @brief Actor class
 *
 * This Actor class holds information about the actors of
 * the movie including their ID, name, and if they can improvise or not.
 * */
class Actor
{
    public:
        /**
         * @brief Constructs a new Actor object.
         * @param id the Actor ID.
         * @param name the actor's name.
         * @param improv if the actor can improv.
         */
        Actor(std::string id, std::string name, bool improv);

        /**
         * @brief Returns the id of Actor.
         * @return id of Actor.
         */
        std::string getID() const { return actorID; }

        /**
         * @brief Sets the value of actorID.
         * @param newID the Actor ID.
         */
        void setID(std::string newID) { actorID = newID; }

        /**
         * @brief Returns the name of Actor.
         * @return name of Actor.
         */
        std::string getName() const { return actorName; }

        /**
         * @brief Sets the value of actorName.
         * @param newName the name of the Actor.
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
         * @brief Convert the Actor object to JSON
         * @return crow::json::wvalue
         */ 
        crow::json::wvalue convertToJson();

        /**
         * @brief Update the Actor object from JSON
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

#endif // ACTOR_H