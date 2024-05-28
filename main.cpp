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

int main(){
    cout << "Hello World";
    return 0;
}