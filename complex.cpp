/* Implement a class Complex which represents the Complex Number data type. Implement the following:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overload operator+ to add two complex numbers. 
3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers */

#include <iostream>
using namespace std;

class Complex {
    float real, img;
public:
    Complex() : real(0), img(0) {} // Default constructor

    Complex operator+(Complex c2) {  //Overloading +
        Complex c3;
        c3.real = real + c2.real;
        c3.img = img + c2.img;
        return c3;
    }

    Complex operator*(Complex c2) {   //Overloading *
        Complex c3;
        c3.real = (real * c2.real) - (img * c2.img);
        c3.img = (real * c2.img) + (img * c2.real);
        return c3;
    }

    friend ostream &operator<<(ostream &out, const Complex &c);
    friend istream &operator>>(istream &in, Complex &c);
};

// Overloading << operator
ostream &operator<<(ostream &out, const Complex &c) {
    out << c.real << " + " << c.img << "i";
    return out;
}

// Overloading >> operator
istream &operator>>(istream &in, Complex &c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.img;
    return in;
}

int main() {
    Complex c1, c2, c3;

    cout << "Please enter the 1st complex number:\n";
    cin >> c1;
    cout<<"1st complex number is: "<<c1<<endl;

    cout << "\nPlease enter the 2nd complex number:\n";
    cin >> c2;
    cout<<"2nd complex number is: "<<c2<<endl;

    c3 = c1 + c2;
    cout << "\nAddition result: " << c3 << endl;

    c3 = c1 * c2;
    cout << "Multiplication result: " << c3 << endl;

    return 0;
}

