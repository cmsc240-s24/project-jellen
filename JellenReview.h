// JellenReview.h
/**
 * @file JellenReview.h
 * @brief Header file for the Jellen Review class.
 *
 * This file contains the declaration of the Jellen Review class along with its
 * member functions and variables.
 */
#ifndef JELLEN_REVIEW_H
#define JELLEN_REVIEW_H

#include <string>
#include "Movie.h"

/**
 * @class JellenReview
 * @brief A class that offers jellen review activity.
 *
 * This class can perform actions such as set/get ratings, set/get
 * reviews, and get/set if jellen would watch it again.
 */
class JellenReview
{
public:
    /**
     * @brief Constructs a new BankAccount object.
     * @param owner the name of the owner of the bank account.
     * @param initialBalance the initial balance of the bank account.
     */
    JellenReview(std::string id, std::string review, int rating, bool wouldWatchAgain);

private:
};

#endif // JELLEN_REVIEW_H