# Library Management System

## Overview

This project was developed as part of my college project.

This project is a simple Library Management System implemented in C++. It provides functionalities to manage a collection of books, including adding new books, updating existing books, deleting books, and viewing books. The system consists of classes such as `Publisher`, `Author`, `Book`, and `Library`. The `Library` class holds a list of books and manages the operations related to books.

## Features

1. **Add a Book**: Add a new book to the library with either default data or user input data.
2. **Update a Book**: Update the details of an existing book.
3. **Delete a Book**: Remove a book from the library.
4. **View All Books**: Display a list of all books in the library.
5. **View a Single Book**: Display the details of a specific book.

## Getting Started

### Prerequisites

- A C++ compiler (GCC, Clang, MSVC, etc.)

### Building the Project

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/library-management-system.git
    cd libraryAppCpp
    ```

2. Compile the project:

    ```bash
    g++ -o library main.cpp
    ```

### Usage

1. **Add a Book**: Follow the prompts to add a book with either default or user-provided details.
2. **Update a Book**: Provide the ISBN of the book to update and the new details.
3. **Delete a Book**: Provide the ISBN of the book to delete.
4. **View All Books**: Displays a list of all books in the library.
5. **View a Single Book**: Provide the ISBN of the book to view its details.

## Contributing

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes.
4. Commit your changes (`git commit -am 'Add new feature'`).
5. Push to the branch (`git push origin feature-branch`).
6. Create a new Pull Request.

## Acknowledgements

- Thanks to the open-source community for their valuable resources and support.
