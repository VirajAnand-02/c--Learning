#include<iostream>
using namespace std;

int divide(int p, int q) {
    if (q) {
        return p / q;
    }
    else {
        throw "Cant divide with zero";
    }
}

int main() {
    try {
        cout << divide(23240, 165) << endl;
        cout << divide(20, 0) << endl;
    }
    catch (string e) {
        cout << e << '\n';
    }
}