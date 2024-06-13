#include<iostream>
using namespace std;

int factorial(int a) {
    if (a < 0) {
        throw a;
    }
    if (a == 0 || a == 1) {
        return 1;
    }
    return factorial(a - 1) * a;
}

int main() {
    int a;
    cout << "enter a number: ";
    cin >> a;
    try {
        cout << "Factorial of " << a << " is : " << factorial(a);
    }
    catch (int e) {
        cout << "Can't find factorial for -ve numbers : " << e << endl;
    }
}