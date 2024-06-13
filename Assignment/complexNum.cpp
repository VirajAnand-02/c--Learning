#include<iostream>
using namespace std;

class Complex {
public:
    float I;
    float J;
    Complex(float i = 0, float j = 0) {
        I = i;
        J = j;
    }
    const Complex Add(Complex& other) {
        return Complex(this->I + other.I, this->J + other.J);
    }
    Complex operator+(Complex& other) {
        return this->Add(other);
    }

    const string toString() {
        string strr = to_string(this->I);
        strr.append(" i + ");
        strr.append(to_string(this->J));
        strr.append(" j ");
        return strr;
    }
};

int main() {
    Complex A;
    cout << "Input First complex number >" << endl << "i:  ";
    cin >> A.I;
    cout << "j: ";
    cin >> A.J;

    Complex B;
    cout << "Input Second complex number >" << endl << "i:  ";
    cin >> B.I;
    cout << "j: ";
    cin >> B.J;

    cout << "Sum of complex number: " << (A + B).toString() << endl;

}