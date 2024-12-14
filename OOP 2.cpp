/*Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and 
price (type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in 
minutes (type float). Write a program that instantiates the book and tape class, allows user to enter data and displays the data members.
If an exception is caught, replace all the data member values with zero values.*/

#include <iostream>
#include <string>
using namespace std;

// Base class
class Publication {
protected:
    string title;
    float price;

public:
    void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        if (price < 0) {
            cerr << "Invalid price! Resetting data.\n";
            resetData();
        }
    }

    void putData() const {
        cout << "Title: " << title << "\nPrice: " << price << endl;
    }

    void resetData() {
        title = "";
        price = 0.0f;
    }
};

// Derived class for Book
class Book : public Publication {
private:
    int pageCount;

public:
    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
        if (pageCount < 0) {
            cerr << "Invalid page count! Resetting data.\n";
            resetData();
        }
    }

    void putData() const {
        Publication::putData();
        cout << "Page Count: " << pageCount << endl;
    }

    void resetData() {
        Publication::resetData();
        pageCount = 0;
    }
};

// Derived class for Tape
class Tape : public Publication {
private:
    float playingTime;

public:
    void getData() {
        Publication::getData();
        cout << "Enter playing time (minutes): ";
        cin >> playingTime;
        if (playingTime < 0) {
            cerr << "Invalid playing time! Resetting data.\n";
            resetData();
        }
    }

    void putData() const {
        Publication::putData();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }

    void resetData() {
        Publication::resetData();
        playingTime = 0.0f;
    }
};

int main() {
    Book bookObj;
    Tape tapeObj;

    cout << "Enter details for Book:\n";
    bookObj.getData();
    cout << "\nDetails of Book:\n";
    bookObj.putData();

    cout << "\nEnter details for Tape:\n";
    tapeObj.getData();
    cout << "\nDetails of Tape:\n";
    tapeObj.putData();

    return 0;
}

