#include<iostream>
using namespace std;

int max(int& a, int& b) {
    return a > b ? a : b;
}
int main() {
    int a, b;
    cout << "Enter two numbers" << endl;
    cout << " A: ";
    cin >> a;
    cout << " B: ";
    cin >> b;
    cout << max(a, b) << " is the greater number. " << endl;
}