# Project Design Document

## Introduction
Jellen's Movie Mart API serves as a digital shop for customers to browse and buy Jellen's favorite films. 

## Background/Context
In the digital age, movie consumption has shifted largely online, demanding advanced systems for cataloging and sales. Customers crave seamless ways to explore and acquire their favorite films, while retailers rely on efficient solutions for inventory management. Enter Jellen's Movie Mart, the premier online movie store, offering a curated selection of handpicked favorites. Powered by the Movie Store API, Jellen's Movie Mart provides a structured platform where information about movies is effortlessly managed and accessed. This not only enriches the customer's browsing journey but also optimizes the store's operations, ensuring that the digital movie marketplace thrives with accessibility and excitement.

## Stakeholders
Customers: Individuals who use the API, directly or indirectly, to explore and purchase movies. They are interested in easy access to a  range of movie data, including genres, directors, movies, and Jellen reviews. Their experience with the API impacts customer satisfaction and influences purchasing decisions.

Movie Retailers: Businesses or individuals who manage the sale and distribution of movies. They rely on the API to effectively manage their inventory, update their product listings, and provide accurate information to their customers. The functionality and reliability of the API are crucial for their daily operations and sales performance.

## Functional Requirements
1. **Resource Creation**
- The service will allow movie retailers to create new resource entries for genres, directors, and movies via POST requests.
- The service will validate all incoming data against predefined schemas before creating a new resource.
- The service will return a `201 Created` status code and the created resource in the response body once one has been successfully created.

2. **Resource Retrieval**
- The service will provide endpoints for customers and movie retailers to retrieve lits of genres, directors, and movies via GET requests.
- The service will allow retrieval of detailed information for a single resource by its unique identifier.
- The service will return a `200 OK` status code and the requested resources in the response body upon successful retrieval.

3. **Resource Update**
- The service will permit movie retailers to update existing resource entries for genres, directors, and movies via PUT requests.
- The service will validate all incoming data for updates against predefined schemas.
- The service will return a `200 OK` status code and the updated resource in the response body upon successful update.

4. **Resource Deletion**
- The service will enable movie retailers to delete resource entries for genres, directors, and movies via DELETE requests.
- The service will return a `204 No Content` status code upon successful deletion.
- The service will return a `403 Forbidden` status code if an unauthorized user attempts to delete a resource.

5. **Data Validation**

- The service shall enforce data validation rules to ensure that all resource data conforms to the expected formats, types, and constraints.
- The service shall return a `400 Bad Request` status code along with error details if validation fails.

6. **Authentication and Authorization**

- The service shall require authentication for users attempting to create, update, or delete resources.
- The service shall authorize users based on their roles, permitting only authorized Jellen to modify or delete resource entries.

7. **Error Handling**

- The service shall implement comprehensive error handling to provide meaningful error messages and appropriate HTTP status codes to the client for all failed operations.
- The service shall return a `404 Not Found` status code when a requested resource cannot be located.
- The service shall return a `500 Internal Server Error` status code in the event of unexpected server-side errors.

## Use Case Description
**Genres**

- **Create (POST)**
As a movie retailer, Jellen wants to add new genres reflecting the latest trends in cinema, ensuring customers can explore and find movies aligned with current popular categories.

- **Read (GET)**
As a movie enthusiast, I want to explore various movie genres to discover new films that match my preferences. As a movie retailer, Jellen needs to review the list of genres to organize the store's layout and recommend movies based on popular categories.

- **Update (PUT)**
As a movie retailer, Jellen aims to update genre information to stay current with changes in movie classification and ensure the inventory is accurately categorized.

- **Delete (DELETE)**
As a movie retailer, Jellen seeks to remove outdated genres from the database to streamline inventory management.

**Directors**
- **Create (POST)**
As a movie retailer, Jellen intends to add profiles for new directors to promote their movies in-store and online.

- **Read (GET)**
As a movie fan, I want to find movies directed by my favorite directors.
As a movie retailer, Jellen needs to access the list of directors to update the inventory and create promotional material for upcoming releases.

- **Update (PUT)**
As a movie retailer, Jellen wants to update director profiles with new movie releases or changes in their career to provide customers with the latest information.

- **Delete (DELETE)**
As a movie retailer, Jellen needs to remove directors who are no longer relevant or whose movies are no longer carried in the store.

**Movies**
- **Create (POST)**
As a movie retailer, Jellen aims to add new movies to the catalog as they are released to offer the latest selections to customers.

- **Read (GET)**
As a movie enthusiast, I want to browse movies to find new releases or classic films I wish to purchase.
As a movie retailer, Jellen needs to view the complete list of movies to manage stock levels and ensure the latest releases are available.

- **Update (PUT)**
As a movie retailer, Jellen wants to update movie information, such as price or genre, to keep the inventory accurate and up-to-date for customers.

- **Delete (DELETE)**
As a movie retailer, Jellen needs to remove movies that are no longer available or have been discontinued from the stock listings.

**DVDs**
- **Create (POST)**
As a movie retailer, Jellen wants to list new DVDs as they become available, ensuring the product offerings are current.

- **Read (GET)**
As a customer, I want to search for DVDs, focusing on finding the best deals or rare finds.
As a movie retailer, Jellen needs to review DVDs in the inventory for pricing adjustments and stock replenishment.

- **Update (PUT)**
As a movie retailer, Jellen wants to modify DVD details, such as price or stock quantity, to reflect changes in inventory or promotions.

- **Delete (DELETE)**
As a movie retailer, Jellen needs to delete listings of DVDs that are sold out or removed from the catalog to maintain an accurate online storefront.

## List Of Resources



## List of End Points


## UML Diagrams

