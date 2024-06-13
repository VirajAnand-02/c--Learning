// Using operator overloading, change the sign of value of a variable.
#include<iostream>
using namespace std;

class MyInt {
public:
    int data;
    MyInt(int data) : data(data) {}
    MyInt operator~() {
        return MyInt(-data);
    }
};

int main() {
    int a;
    cout << "Enter an intger : ";
    cin >> a;
    MyInt x(a);
    cout << "Original value: " << x.data << endl;
    MyInt y = ~x;
    cout << "Value after changing sign: " << y.data << endl;
    return 0;
}
