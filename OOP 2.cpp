/*Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) of publications. From
this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float). Write a program that instantiates the book and tape class, allows user to enter data
and displays the data members. If an exception is caught, replace all the data member values with zero values.*/

#include<iostream>
using namespace std;
class publication
{ public:
string title;
float price;
void getdata()
{ cout<<"Enter title of book: ";
cin>>title;
cout<<"Enter price of book: ";
cin>>price;
}
void putdata()
{ cout<<"Title of book is "<<title;
cout<<"\nPrice of book is "<<price;
}
};
class book : public publication
{ public:
int pg_count;
void getdata1()
{ cout<<"Enter page count of book: ";
cin>>pg_count;
}
void putdata1()
{ cout<<"Page count of book is "<<pg_count;
}
};
class tape : public publication
{ public:
float t_time;
void getdata2()
{ cout<<"Enter tape time in mins: ";
cin>>t_time;
}
void putdata2()
{ cout<<"Tape time in mins is "<<t_time;
}
};
int main()
{ book B;
tape T;
B.getdata();
B.getdata1();
T.getdata2();
cout<<"\n";
B.putdata();
cout<<"\n";
B.putdata1();
cout<<"\n";
T.putdata2();
return 0;
}
