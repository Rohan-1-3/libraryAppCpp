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