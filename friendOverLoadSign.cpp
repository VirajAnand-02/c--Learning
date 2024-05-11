// Using friend operator function, invert sign of operator of variable.
#include<iostream>
using namespace std;

class MyInt {
public:
    int data;
    MyInt(int data) : data(data) {}
    friend MyInt operator-(const MyInt& num);
    void display() const {
        cout << "Value: " << data << endl;
    }
};

MyInt operator-(const MyInt& num) {
    return MyInt(-num.data);
}

int main() {
    MyInt x(5);
    cout << "Original value: ";
    x.display();
    MyInt y = -x;
    cout << "Value after changing sign: ";
    y.display();
    return 0;
}
