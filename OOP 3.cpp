/* Implement a class Complex which represents the Complex Number data type. Implement the following 1. Constructor (including a default constructor which creates the complex number 0+0i). 2. Overload
operator+ to add two complex numbers. 3. Overload operator* to multiply two complex numbers. 4. Overload operators << and >> to print and read Complex Numbers */

 #include <iostream>
 using namespace std;
 class complex
 {
 float real,img;
 public:
 complex operator+(complex);
 complex operator*(complex);
 friend ostream & operator<<(ostream &,complex &);
 friend istream & operator>>(istream &,complex &);
 };
 complex complex::operator+(complex c2)
 {
 complex c3;
 c3.real=real+c2.real;
 c3.img=img+c2.img;
 return c3;
 }
 complex complex::operator*( complex c2)
 {
 complex c3,c1;
 c3.real=c1.real*c2.real-c1.img*c2.img;
 c3.img=c1.real*c2.img+c1.img*c2.real;
 return c3;
 }
 ostream & operator<<(ostream &out,complex &c)
 {
 cout<<"\nreal part:";
 out<<c.real;
 cout<<"\nimaginary part:";
 out<<c.img;
 return out;
 }
 istream & operator>>(istream &in,complex &c)
 {
 cout<<"Enter a real part:"<<endl;
 in>>c.real;
 cout<<"Enter the imaginary part:"<<endl;
 in>>c.img;
return in;
 }
 int main()
 {
 complex c1,c2,c3;
 cout<<"please enter 1st number \n";
 cin>>c1;
 cout<<"please enter 2nd number \n";
 cin>>c2;
 //cout<<c1;
 //cout<<c2;
 c3=c1+c2;
 cout<<"\nAddition is";
 cout<<c3;
 cout<<"\nMultiplication is";
 c3=c1*c2;
 cout<<c3;
 return 0;
 }
