#include<iostream>
using namespace std;

int main() {
    try {
        int a;
        cout << "enter a number bellow 10: ";
        cin >> a;
        if (!(a < 10)) {
            throw a;
        }
        else {
            cout << "Number is bllow 10, no exception to handel" << endl;
        }
    }
    catch (int e) {
        std::cout << "EXCEPTION, Entered number is greater, equal 10 : enterd-" << e << '\n';
    }

}