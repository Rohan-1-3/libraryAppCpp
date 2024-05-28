#include <iostream>
#include <string>
using namespace std;

void displayChoice() {
    cout << "\n1) Input data to update\n2) Input enter to avoid update\n";
}

void displayLines(){
    cout << "\n--------------------------------------------------------------------------------\n";
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
        displayLines();
        cout << "Details of the Publisher: \n";
        cout << "Name: " << name << endl << "Address: " << address << endl;
        displayLines();
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
        displayLines();
        cout << "Details of the Author: \n";
        cout << "Name: " << name << endl << "Title: " << title << endl;
        displayLines();
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

    string getName(){
        return name;
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
        Publisher& newPublisher, Author& newAuthor) {
        title = newTitle;
        isbn = newISBN;
        yearReleased = newYearReleased;
        editionYear = newEditionYear;
        price = newPrice;
        publisher = new Publisher(newPublisher);
        author = new Author(newAuthor);
    }


    void display() {
        displayLines();
        cout << endl << "Details of the book: " << endl;
        cout << "Title: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Year Released: " << yearReleased << endl << "Edition Year: " << editionYear << endl;
        cout << "Price: " << price << endl;
        publisher->display();
        author->display();
        displayLines();
    }

    void displayBookTitles(int n){
        cout << n << "\t\t" << title << "\t\t" << author->getName() << "\t\t" << price << endl;
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
    Library(){
        books = nullptr;
    }

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
        for (int i = 0; i < Book::bookCount; ++i) {
            tempBooks[i] = books[i];  // Copy existing books
        }
        tempBooks[Book::bookCount] = Book();  // Add new book with default data
    } else if (choice == 1) {
        for (int i = 0; i < Book::bookCount; ++i) {
            tempBooks[i] = books[i];  // Copy existing books
        }
        tempBooks[Book::bookCount] = getBookData();  // Add new book with user data
    } else {
        cout << "Invalid Input" << endl;
        delete[] tempBooks;
        return;
    }
    delete[] books; // Deallocate memory for the old array
    books = tempBooks; // Assign the new array to books pointer
    ++Book::bookCount;
    displayLines();
    cout << "New Book Added" << endl;
    displayLines();
}

    void displayAllBooks() {
        displayLines();
        cout << "S.N." << "\t\t" << "Title" << "\t\t" << "Author" << "\t\t" << "Price" << endl;
        for (int i = 0; i < Book::bookCount; i++) {
            books[i].displayBookTitles(i+1);
        }
        displayLines();
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
        displayLines();
        cout << "Book deleted successfully." << endl;
        displayLines();
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
    int choice;

    do {
        cout << "\nLibrary Menu:" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Display a Book" << endl;
        cout << "4. Delete a Book" << endl;
        cout << "5. Update a Book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the buffer

        switch(choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.displayAllBooks();
                break;
            case 3:
                int bookIndex;
                cout << "Enter the index of the book to display: ";
                cin >> bookIndex;
                lib.displayBook(bookIndex-1);
                break;
            case 4:
                int bookIndexToDelete;
                cout << "Enter the index of the book to delete: ";
                cin >> bookIndexToDelete;
                lib.deleteBook(bookIndexToDelete-1);
                break;
            case 5:
                int bookIndexToUpdate;
                cout << "Enter the index of book to update: ";
                cin >> bookIndexToUpdate;
                lib.updateBook(bookIndexToUpdate-1);
                break;
            case 6:
                cout << "Exiting the library." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    } while(choice != 6);

    return 0;
}
