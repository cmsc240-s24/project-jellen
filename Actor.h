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

#include <string>
#include <crow.h>
#include "Personnel.h"

/**
 * @class Actor
 * @brief Actor class
 *
 * This Actor class holds information about the actors of
 * the movie including their ID, name, and if they can improvise or not.
 * */
class Actor : public Personnel
{
    public:
        /**
         * @brief Constructs a new Actor object.
         */
        Actor() {}

        /**
         * @brief Constructs a new Actor object.
         */
        Actor(crow::json::rvalue readValueJson);

        /**
         * @brief Returns the value of if the actor can improv.
         * @return true if the actor can improv, false if not.
         */
        bool getImprov() const { return canImprov; }

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
         * @brief canImprov
        */
        bool canImprov;
};

#endif // ACTOR_H