#include <iostream>
#include <string>
using namespace std;

void displayChoice() {
    cout << "\n1) Input data to update\n2) Input enter to avoid update\n";
}

class Publisher {
    string name;
    string address;

public:
    Publisher() {
        name = "ABC Publications";
        address = "Some Location, Some Street";
    }

    Publisher(string newName, string newAddress) {
        name = newName;
        address = newAddress;
    }

    void display() {
        cout << "\nDetails of the Publisher: \n";
        cout << "Name: " << name << endl << "Address: " << address << endl;
    }

    void updateData() {
        string tempString;
        displayChoice();
        cout << "\nEnter the new name of the Publisher:";
        getline(cin, tempString);
        if (!tempString.empty())
            name = tempString;

        cout << "\nEnter the new address of the Publisher:";
        getline(cin, tempString);
        if (!tempString.empty())
            address = tempString;
    }
};

class Author {
    string name;
    string title;

public:
    Author() {
        name = "John Doe";
        title = "Some Title";
    }

    Author(string newName, string newTitle) {
        name = newName;
        title = newTitle;
    }

    void display() {
        cout << "\nDetails of the Author: \n";
        cout << "Name: " << name << endl << "Title: " << title << endl;
    }

    void updateData() {
        string tempString;
        displayChoice();
        cout << "\nEnter the new name of the Author:";
        getline(cin, tempString);
        if (!tempString.empty())
            name = tempString;

        cout << "\nEnter the new title of the Author:";
        getline(cin, tempString);
        if (!tempString.empty())
            title = tempString;
    }
};

class Book {
    string title;
    string isbn;
    int yearReleased;
    int editionYear;
    float price;
    Publisher* publisher;
    Author* author;

public:
    static int bookCount;

    Book() {
        title = "Some Title";
        isbn = "1234567890";
        yearReleased = 1980;
        editionYear = 2024;
        price = 420.0;
        publisher = new Publisher();
        author = new Author();
    }

    Book(string newTitle, string newISBN, int newYearReleased, int newEditionYear, float newPrice,
         const Publisher& newPublisher, const Author& newAuthor) :
        title(newTitle), isbn(newISBN), yearReleased(newYearReleased), editionYear(newEditionYear), price(newPrice),
        publisher(new Publisher(newPublisher)), author(new Author(newAuthor)) {}

    void display() {
        cout << endl << "Details of the book: " << endl;
        cout << "Title: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Year Released: " << yearReleased << endl << "Edition Year: " << editionYear << endl;
        cout << "Price: " << price << endl;
        publisher->display();
        author->display();
    }

    void update() {
        string tempString;
        cout << endl << "Enter the details of the book: " << endl;
        displayChoice();
        cout << "Enter Book Title: ";
        getline(cin, tempString);
        if (!tempString.empty())
            title = tempString;

        cout << "Enter Book ISBN: ";
        getline(cin, tempString);
        if (!tempString.empty())
            isbn = tempString;

        cout << "Enter Book Year Released: ";
        cin >> yearReleased;

        cout << "Enter Book Edition Year: ";
        cin >> editionYear;

        cout << "Enter Book Price: ";
        cin >> price;

        cin.ignore(); // Clear the newline character from the buffer

        author->updateData();
        publisher->updateData();
    }
};

int Book::bookCount = 0;

class Library {
    Book* books;

public:
    Library() : books(nullptr) {}

    ~Library() {
        delete[] books; // Deallocate memory for the array of books
    }

    void addBook() {
        Book* tempBooks = new Book[Book::bookCount + 1];
        int choice;
        cout << "0) Create a default Book\n1) Create a book with fixed data\n";
        cin >> choice;
        cin.ignore();
        if (choice == 0) {
            tempBooks[Book::bookCount] = Book();
        } else if (choice == 1) {
            tempBooks[Book::bookCount] = getBookData();
        } else {
            cout << "Invalid Input" << endl;
            delete[] tempBooks;
            return;
        }
        delete[] books; // Deallocate memory for the old array
        books = tempBooks; // Assign the new array to books pointer
        ++Book::bookCount;
        cout << "New Book Added" << endl;
    }

    void displayAllBooks() {
        for (int i = 0; i < Book::bookCount; i++) {
            cout << i << ": ";
            books[i].display();
        }
    }

    void displayBook(int n) {
        if (n < 0 || n >= Book::bookCount) {
            cout << "Invalid book index." << endl;
            return;
        }
        books[n].display();
    }

    void updateBook(int n) {
        if (n < 0 || n >= Book::bookCount) {
            cout << "Invalid book index." << endl;
            return;
        }
        books[n].update();
    }

    void deleteBook(int n) {
        if (n < 0 || n >= Book::bookCount) {
            cout << "Invalid book index." << endl;
            return;
        }

        Book* tempBooks = new Book[Book::bookCount - 1];
        for (int i = 0, j = 0; i < Book::bookCount; ++i) {
            if (i != n) {
                tempBooks[j++] = books[i];
            }
        }
        delete[] books;
        books = tempBooks;
        --Book::bookCount;
        cout << "Book deleted successfully." << endl;
    }

private:
    Book getBookData() {
        string title, isbn;
        int yearReleased, editionYear;
        float price;

        // cin.ignore(); // Clear the newline character from the buffer

        cout << "\nEnter the details of the book:" << endl;
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Book ISBN: ";
        getline(cin, isbn);
        cout << "Enter Book Year Released: ";
        cin >> yearReleased;
        cout << "Enter Book Edition Year: ";
        cin >> editionYear;
        cout << "Enter Book Price: ";
        cin >> price;

        string publisherName, publisherAddress;
        cout << "Enter Publisher Details:\n";
        cout << "Enter Publisher Name: ";
        cin.ignore(); // Clear the newline character from the buffer
        getline(cin, publisherName);
        cout << "Enter Publisher Address: ";
        getline(cin, publisherAddress);

        string authName, authPosition;
        cout << "Enter author name: ";
        getline(cin, authName);
        cout << "Enter author position: ";
        getline(cin, authPosition);

        Publisher publisher(publisherName, publisherAddress);
        Author author(authName, authPosition);
        return Book(title, isbn, yearReleased, editionYear, price, publisher, author);
    }
};

int main() {
    Library lib;
    lib.addBook();
    lib.addBook();
    cout << "\n--------------------------------------------\n";
    lib.displayBook(0);
    cout << "\n--------------------------------------------\n";
    lib.displayAllBooks();
    cout << "\n--------------------------------------------\n";
    lib.deleteBook(0);
    cout << "\n--------------------------------------------\n";
    lib.displayAllBooks();
    return 0;
}
