#ifndef GENRE_H
#define GENRE_H

#include <string>

/**
 * @brief Genre class
 *
 * This Genre class holds information about the genre of
 * the movie including its ID, genre.
 */

class Genre
{
public:
    /**
     * @brief Construct a new Genre object
     *
     */
    Genre() {}

    Genre(crow::json::rvalue read);

    /**
     * @brief Get the Genre ID object
     *
     * @return int
     */
    int getGenreID() const;

    /**
     * @brief Get the Genre object
     *
     * @return std::string
     */
    std::string getGenre() const;

    /**
     * @brief Set the Genre ID object
     *
     * @param genreID
     */
    void setGenreID(int genreID);

    /**
     * @brief Set the Genre object
     *
     * @param genre
     */
    void setGenre(std::string genre);

    /**
     * @brief Convert the Genre object to JSON
     *
     * @return crow::json::wvalue
     */
    crow::json::wvalue convertToJson();

    /**
     * @brief Update the Genre object from JSON
     *
     * @param readValueJson
     */
    void updateFromJson(crow::json::rvalue readValueJson);

private:
    /**
     * @brief Genre ID
     */
    std::string genreID;

    /**
     * @brief Genre
     */
    std::string genre;
};

#endif // GENRE_H