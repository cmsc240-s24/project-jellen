#ifndef CART_H
#define CART_H

#include <string>
#include <vector>

/**
 * @brief Cart class
 *
 * This Cart class holds information about the cart of
 * the user including its ID, movies.
*/
class Cart
{
public:
    /**
     * @brief Construct a new Cart object
     */
    Cart() {}

    /**
     * @brief Construct a new Cart object
     *
     * @param readValueJson
     */
    Cart(crow::json::rvalue readValueJson);

    /**
     * @brief Get the Cart ID object
     *
     * @return std::string
     */
    std::string getCartID() const { return cartID; }

    /**
     * @brief Get the Movies object
     *
     * @return std::vector<Movies>
     */
    std::vector<Movie> getMovies() const { return movies; }

    /**
     * @brief Set the Cart ID object
     *
     * @param cartID
    */
    void setCartID(std::string idParam) { cartID = idParam; }

    /**
     * @brief Set the Movies object
     *
     * @param movies
     */
    void setMovies(std::vector<Movie> moviesParam) { movies = moviesParam; }

    /**
     * @brief Convert the Cart object to JSON
     *
     * @return crow::json::wvalue
    */
    crow::json::wvalue convertToJson();

    /**
     * @brief Update the Cart object from JSON
     *
     * @param readValueJson
     */
    void updateFromJson(crow::json::rvalue readValueJson);

private:
    /**
     * @brief Cart ID
     */
    std::string cartID;
    /**
     * @brief Movies
     */
    std::vector<Mvie> movies;
};

#endif // CART_H