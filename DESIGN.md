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


## List Of Resources



## List of End Points


## UML Diagrams

