#include <iostream>

using namespace std;

// Base class for addition
class Addition {
protected:
    int num1;
    int num2;

public:
    Addition(int a, int b) : num1(a), num2(b) {}

    // Perform addition
    int add() {
        return num1 + num2;
    }
};

// Derived class for multiplication, inheriting from Addition
class Multiplication : public Addition {
public:
    Multiplication(int a, int b) : Addition(a, b) {}

    // Perform multiplication using additive properties
    int multiply() {
        int result = 0;
        for (int i = 0; i < num2; ++i) {
            result += add(); // Multiplication using addition property
        }
        return result;
    }
};

int main() {
    int num1, num2;

    // Input two numbers
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Create object of Multiplication class
    Multiplication obj(num1, num2);

    // Calculate multiplication using additive properties
    int result = obj.multiply();

    // Output result
    cout << "Multiplication of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
