#include<iostream>
using namespace std;

class Base {
public:
    int zero;
    int argVal;
    Base(int arg) {
        argVal = arg;
        zero = 0;
    }
};

int main() {
    Base var(70);
    cout << var.zero << var.argVal << endl;
}