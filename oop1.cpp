/*Develop a program in C++ to create a database of student’s information system containing the following information: Name, Roll number, Class, Division, Date of Birth, Blood group, contact address, Telephone
number, Driving license no. and other. Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this 
pointer, inline code and dynamic memory allocation operatorsnew and delete as well as exception*/

#include <iostream>
#include <string>
using namespace std;

class studdata;

class student {
    string name, Class, dob;
    int roll_no;
    char* div;
    char* bloodgroup;
    static int count;

public:
    // Default constructor
    student() {
        name = " ";
        roll_no = 0;
        Class = " ";
        div = new char[50]; // Allocate enough space for division
        dob = "dd/mm/yyyy";
        bloodgroup = new char[5]; // Allocate space for blood group
    }

    // Destructor
    ~student() {
        delete[] div; // Delete the array allocated for div
        delete[] bloodgroup; // Delete the array allocated for bloodgroup
    }

    static int getcount() {
        return count;
    }

    void getdata(studdata* st);
    void displaydata(studdata* st1);
};

// Static member initialization
int student::count = 0;

class studdata {
    string address;
    long* telno;
    long* drivinglicense;
    friend class student; // Using friend function

public:
    // Default constructor
    studdata() {
        address = " ";
        telno = new long; // Using new operator
        drivinglicense = new long; // Using new operator
    }

    // Destructor
    ~studdata() {
        delete telno; // Using delete operator
        delete drivinglicense; // Using delete operator
    }

    void getstuddata() {
        cout << "Enter Address of student: ";
        cin.ignore(); // Clear the newline character from previous input
        getline(cin, address); // Using getline to get proper address with spaces
        cout << "Enter telephone no. of the student: ";
        cin >> *telno;
        cout << "Enter driving license no. of student: ";
        cin >> *drivinglicense;
    }

    void displaystuddata() {
        cout << "Student address: " << address << endl;
        cout << "Student's telephone no.: " << *telno << endl;
        cout << "Student's driving license no.: " << *drivinglicense << endl;
    }
};

void student::getdata(studdata* st) {
    cout << "Enter student's name: ";
    cin.ignore(); // Clear the newline character
    getline(cin, name);
    cout << "Enter roll no. of student: ";
    cin >> roll_no;
    cout << "Enter the class of student: ";
    cin.ignore(); // Clear the newline character
    getline(cin, Class);
    cout << "Enter the division of student: ";
    cin >> div; // Read directly into div
    cout << "Enter DOB of student: ";
    cin.ignore(); // Clear the newline character
    getline(cin, dob);
    cout << "Enter the blood group of student: ";
    cin >> bloodgroup; // Read directly into bloodgroup
    st->getstuddata(); // Using this pointer to get the data of class studdata
    count++;
}

void student::displaydata(studdata* st1) {
    cout << "Name of student is: " << name << endl;
    cout << "Roll no. of student is: " << roll_no << endl;
    cout << "Class of student is: " << Class << endl;
    cout << "Division of student is: " << div << endl;
    cout << "Date of birth of student is: " << dob << endl;
    cout << "Blood group of student is: " << bloodgroup << endl;
    st1->displaystuddata(); // Using this pointer to display data of class studdata
}

int main() {
    student* stud1[100];
    studdata* stud2[100];
    int n = 0;
    char ch;

    do {
        stud1[n] = new student;
        stud2[n] = new studdata;
        cout << ".........ENTER STUDENT DATA.............." << endl;
        stud1[n]->getdata(stud2[n]);
        n++;
        cout << "Do you want to add another student? press y for yes and n for no: ";
        cin >> ch;
        cin.ignore(); // Clear the newline character
    } while (ch == 'y' || ch == 'Y');

    for (int i = 0; i < n; i++) {
        cout << ".............STUDENT DATABASE............." << endl;
        stud1[i]->displaydata(stud2[i]);
    }
    
    cout << "...........................";
    cout << "Total students: " << student::getcount() << endl;

    // Cleanup
    for (int i = 0; i < n; i++) {
        delete stud1[i];
        delete stud2[i];
    }
    return 0;
}

