/*Develop a program in C++ to create a database of student’s information system containing the following information: Name, Roll number, Class, Division, Date of Birth, Blood group, contact address, Telephone
number, Driving license no. and other. Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this 
pointer, inline code and dynamic memory allocation operatorsnew and delete as well as exception*/


#include<iostream>
 #include<string.h>
 using namespace std;
 class studdata;
 class student{
 string name, Class, dob;
 int roll_no;
 char* div;
 char* bloodgroup;
 static int count;
 public:
 //DEFAULT CONTRUCTOR
 student(){
 name=" ";
 roll_no=0;
 Class=" ";
 div= new char;        //USING NEW OPERATOR
 dob="dd/mm/yyyy";
 bloodgroup= new char[5];       //USING NEW OPERATOR
 }
 //DESTRUCTOR
~student(){
 delete div;
 delete[] bloodgroup;       //USING DELETE
 OPERATOR }
 static int getcount(){        //STATIC MEMEBER FUNCTION
 return count;
 }
 void getdata(studdata*);
 void displaydata(studdata*);
 };
 class studdata{
 string address;
 long int* telno;
 long int* drivinglicense;
 friend class student;       //USING FRIEND FUNCTION
 public:
 //USING DEFAULT CONSTRUCTOR
 studdata(){
 address = " ";
 telno=new long;        // USING NEW OPERATOR
 drivinglicense=new long;         // USING NEW OPERATOR }
 //USING DESTRUCTOR
 ~studdata(){
 delete telno;
 delete drivinglicense; //USING DELETE OPEARTOR
 }
 void getstuddata(){
 cout<<"Enter Address of student: ";
 cin.get();
 getline(cin, address);          //USING GETLINE FUNCTION TO GET A PROPER ADDRESS WITH SPACES
 cout<<"Enter telephone no. of the student: ";
 cin>>*telno;
 cout<<"Enter driving license no. of student:";
 cin>>*drivinglicense;
 }
 void displaystuddata(){
 cout<<"Student address: "<<address<<endl;
 cout<<"student's telephone no.: "<<*telno<<endl;
 cout<<"Students's driving license no.: "<<*drivinglicense<<endl;
 }
 };
 inline void student::getdata(studdata*st){         //USING INLINE FUNCTION
 cout<<"Enter student's name: ";
 getline(cin, name);
 cout<<"Enter roll no. of student: ";
 cin>>roll_no;
 cout<<"Enter the class of student: ";
 cin.get();
 getline(cin, Class);
 cout<<"Enter the division of student: ";
 cin>>div;
 cout<<"Enter DOB of student: ";
 cin.get();
 getline(cin, dob);
 cout<<"Enter the bloodgroup of student: ";
 cin>>bloodgroup;
 st->getstuddata();          //USING THIS POINTER TO GET THE DATA OF CLASS STUDDATA
 count++;
 }
 inline void student :: displaydata(studdata*st1){
 cout<<"Name of student is: "<<name<<endl;
 cout<<"Roll no. of student is: "<<roll_no<<endl;
 cout<<"Class of student is: "<<Class<<endl;
 cout<<"Division of student is: "<<div<<endl;
 cout<<"Date of birth of student is: "<<dob<<endl;
 cout<<"Bloodgroup pf student is: "<<bloodgroup<<endl;
 st1->displaystuddata();         //USING THIS POINTER TO DISPLAY DATA OF CLASS STUDDATA }
 int student::count;
 int main(){
 student*stud1[100];
 studdata*stud2[100];
 int n=0;
 char ch;
 do{
 stud1[n]=new student;
 stud2[n]=new studdata;
 cout<<".........ENTER STUDENT DATA.............."<<endl;
 stud1[n]->getdata(stud2[n]);
 n++;
 cout<<"Do you want to add another student? press y for yes and n for no:
 "; cin>>ch;
 cin.get();
 }while(ch=='y' || ch=='Y');
 for(int i=0; i<n; i++){
 cout<<".............STUDENT DATABASE............."<<endl;
 stud1[i]->displaydata(stud2[i]);
 }
 cout<<"...........................";
 cout<<"Total student: "<<student::getcount();
 cout<<endl;
 for(int i=0; i<n;i++){
 delete stud1[i];
 delete stud2[i];
 }
 return 0;
}
