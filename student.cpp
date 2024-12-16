/*Develop a program in C++ to create a database of student’s information system containing the following information: Name, Roll number, Class, Division,
Date of Birth, Blood group, contact address, Telephone number, Driving license no. and other. Construct the database with suitable member functions. 
Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory
allocation operatorsnew and delete as well as exception*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class studdata;

class student {
    string name, Class, dob;
    int roll_no;
    string div;  // Use string instead of char*
    string bloodgroup;  // Use string instead of char*
    static int count;

public:
    // Default constructor
    student() {
        name = " ";
        roll_no = 0;
        Class = " ";
        div = "";
        dob = "dd/mm/yyyy";
        bloodgroup = "";
    }

    // Destructor
    ~student() {
        // No need for explicit deletion as strings manage their own memory
    }

    // Static function to return student count
    static int getcount() {
        return count;
    }

    // Member functions
    void getdata(studdata* st);
    void displaydata(studdata* st1);
};

// Static member initialization
int student::count = 0;

class studdata {
    string address;
    long telno;
    long drivinglicense;
    friend class student;  // Friend class allows access to private members

public:
    // Default constructor
    studdata() {
        address = " ";
        telno = 0;
        drivinglicense = 0;
    }

    // Destructor
    ~studdata() {
        // No dynamically allocated memory, so no explicit cleanup required
    }

    // Input and display functions
    void getstuddata() {
        cout << "Enter Address of student: ";
        cin.ignore();  // Clear the newline character from previous input
        getline(cin, address);  // Get address with spaces
        cout << "Enter telephone no. of the student: ";
        cin >> telno;
        cout << "Enter driving license no. of student: ";
        cin >> drivinglicense;
    }

    void displaystuddata() const {
        cout << "Student address: " << address << endl;
        cout << "Student's telephone no.: " << telno << endl;
        cout << "Student's driving license no.: " << drivinglicense << endl;
    }
};

// Member function definitions for student class
void student::getdata(studdata* st) {
    cout << "Enter student's name: ";
    cin.ignore();  // Clear the newline character
    getline(cin, name);
    cout << "Enter roll no. of student: ";
    cin >> roll_no;
    cin.ignore();
    cout << "Enter the class of student: ";
    getline(cin, Class);
    cout << "Enter the division of student: ";
    getline(cin, div);
    cout << "Enter DOB of student (dd/mm/yyyy): ";
    getline(cin, dob);
    cout << "Enter the blood group of student: ";
    getline(cin, bloodgroup);

    // Call method of studdata to input additional details
    st->getstuddata();

    // Increment the static student count
    count++;
}

void student::displaydata(studdata* st1) {
    cout << "\nName of student: " << name;
    cout << "\nRoll no. of student: " << roll_no;
    cout << "\nClass of student: " << Class;
    cout << "\nDivision of student: " << div;
    cout << "\nDate of birth of student: " << dob;
    cout << "\nBlood group of student: " << bloodgroup << endl;

    // Call display function of studdata
    st1->displaystuddata();
}

int main() {
    vector<student*> stud1;  // Use vector for dynamic student storage
    vector<studdata*> stud2;
    char ch;

    do {
        // Allocate new student and studdata dynamically
        student* s = new student;
        studdata* d = new studdata;

        // Input student details
        cout << ".........ENTER STUDENT DATA.............." << endl;
        s->getdata(d);

        // Add pointers to vectors
        stud1.push_back(s);
        stud2.push_back(d);

        // Ask if the user wants to add another student
        cout << "Do you want to add another student? (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    // Display all students
    for (size_t i = 0; i < stud1.size(); ++i) {
        cout << ".............STUDENT DATABASE............." << endl;
        stud1[i]->displaydata(stud2[i]);
    }

    cout << "..........................." << endl;
    cout << "Total students: " << student::getcount() << endl;

    // Cleanup dynamically allocated memory
    for (size_t i = 0; i < stud1.size(); ++i) {
        delete stud1[i];
        delete stud2[i];
    }

    return 0;
}
