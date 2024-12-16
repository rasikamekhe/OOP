/* Write C++ program that creates an output file, writes information to it, closes the file, open it again as an input file & read the information from the file. */

#include<iostream>
#include<fstream>
using namespace std;

class student {
    string name, dob;
    int roll_no;
    double contactno;
public:
    void getdata() {
        cout << "Enter the name of student: ";
        cin.ignore(); // Ignore the newline left by previous input
        getline(cin, name); // Get the student's name with spaces
        cout << "Enter roll no. of the student: ";
        cin >> roll_no;
        cout << "Enter Date of birth of student: ";
        cin >> dob;
        cout << "Enter contact number of student: ";
        cin >> contactno;
    }

    void displaydata() {
        cout << "Name of student: " << name << endl;
        cout << "Roll no. of student: " << roll_no << endl;
        cout << "DOB of student: " << dob << endl;
        cout << "Contact no. of student: " << contactno << endl;
    }

    // Function to write the object data to the file
    void writeToFile(fstream &f) {
        f.write((char*)this, sizeof(*this));
    }

    // Function to read the object data from the file
    void readFromFile(fstream &f) {
        f.read((char*)this, sizeof(*this));
    }
};

int main() {
    student obj[5];
    fstream f;
    int i, n;

    // Open binary file in write mode
    f.open("aa.txt", ios::out | ios::binary);
    if (!f) {
        cerr << "Error opening file for writing! Check if the directory is accessible and you have write permissions." << endl;
        return 1;
    }

    cout << "\nEnter the number of students you want to store: ";
    cin >> n;

    // Get data from the user and write it to the file
    for (i = 0; i < n; i++) {
        cout << "\nEnter information of student " << i + 1 << endl;
        obj[i].getdata();
        obj[i].writeToFile(f); // Write data to file
    }

    f.close(); // Close file after writing

    // Open binary file in read mode
    f.open("aa.txt", ios::in | ios::binary);
    if (!f) {
        cerr << "Error opening file for reading! Check if the file exists and is readable." << endl;
        return 1;
    }

    cout << "\n..............STUDENT INFORMATION............" << endl;

    // Read and display student data from the file
    for (i = 0; i < n; i++) {
        cout << "Student " << i + 1 << endl;
        obj[i].readFromFile(f); // Read data from file
        obj[i].displaydata(); // Display data
    }

    f.close(); // Close file after reading

    return 0;
}
