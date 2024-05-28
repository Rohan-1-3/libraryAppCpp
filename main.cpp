#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void displayChoice(){
    cout << "1) Enter data to update\n2) Enter n to avoid update\n";
}

class Publisher{
    string name;
    string address;
    public:
    Publisher(){
        name = "ABC Publications";
        address = "Some Location, Some Street";
    }
    Publisher(string newName, string newAddress){
        name = newName;
        address = newAddress;
    }

    void display(){
        cout << "\nDetails of the Publisher: \n";
        cout << "Name: " << name << endl << "Address: " << address << endl;
    }

    void updateData(){
        string tempString;
        cout << "\nEnter the new name of the Publisher:";
        displayChoice();
        cin >> tempString;
        if(tempString != "n")
            name = tempString;

        cout << "\nEnter the new address of the Publisher: ";
        displayChoice();
        cin >> tempString;
        if(tempString != "n")
            address = tempString;
    }
};

class Author{
    string name;
    string title;

    public:
    Author(){
        name = "John Doe";
        title = "Some Title";
    }
    Author(string newName, string newTitle){
        name = newName;
        title = newTitle;
    }

    void display(){
        cout << "\nDetails of the Author: \n";
        cout << "Name: " << name << endl << "Address: " << title << endl;
    }

    void update(){
        string tempString;
        cout << "\nEnter the new name of the Author:";
        displayChoice();
        cin >> tempString;
        if(tempString != "n")
            name = tempString;

        cout << "\nEnter the new title of the Author: ";
        displayChoice();
        cin >> tempString;
        if(tempString != "n")
            title = tempString;
    }
};

class Book{
    string title;
    string isbn;
    int yearReleased;
    int editionYear;
    float price;
    Publisher* publisher;
    Author* author;

    public:
    static int bookCount;
    Book(){
        bookCount++;
        title = "Some Title";
        isbn = "1234567890";
        yearReleased = 1980;
        editionYear = 2024;
        price = 420.0;
        publisher = new Publisher();
        author = new Author();
    }

    Book(string newTitle, string newISBN, int newYearReleased, int newEditionYear, float newPrice,
        Publisher& newPublisher, Author& newAuthor){
            bookCount++;
            title = newTitle;
            isbn = newISBN;
            yearReleased = newYearReleased;
            editionYear = newEditionYear;
            price = newPrice;
            publisher = new Publisher(newPublisher);
            author = new Author(newAuthor);
    };

    void display(){
        cout << endl << "Details of the book: " << endl;
        cout << "Title: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Year Released: " << yearReleased << endl << "Edition Year: " << editionYear << endl;
        cout << "Price: " << price << endl;
        publisher->display();
        author->display();
    }
};

int Book::bookCount = 0;



int main(){

    return 0;
}