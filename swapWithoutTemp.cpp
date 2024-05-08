#include<iostream>
using namespace std;

void swapWithoutTemp(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int a = 1;
    int b = 2;
    swapWithoutTemp(a, b);
    cout << "Vars: " << a << " | " << b;
}
