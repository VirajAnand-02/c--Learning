#include<iostream>
using namespace std;

struct largest {
    int a;
    int b;
    int largest_num() {
        return a > b ? a : b;
    }
};

int main() {
    largest nums;
    cout << "Enter two numbers" << endl;
    cout << " A: ";
    cin >> nums.a;
    cout << " B: ";
    cin >> nums.b;
    cout << nums.largest_num() << " is the greater number. " << endl;
}