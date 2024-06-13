#include <iostream>

class Sample {
public:
    int value;

    // Constructor to initialize the value
    Sample(int v) : value(v) {}

    // Copy constructor
    Sample(const Sample &obj) {
        value = obj.value;
        std::cout << "Copy constructor called." << std::endl;
    }

    // Assignment operator
    Sample& operator=(const Sample &obj) {
        if (this != &obj) { // Avoid self-assignment
            value = obj.value;
        }
        std::cout << "Assignment operator called." << std::endl;
        return *this;
    }
};

int main() {
    Sample obj1(10); // Create an object with initial value 10
    Sample obj2 = obj1; // Invoke copy constructor

    Sample obj3(20); // Another object with different initial value
    obj3 = obj1; // Copy the value using assignment operator

    std::cout << "obj1 value: " << obj1.value << std::endl;
    std::cout << "obj2 value (copied using copy constructor): " << obj2.value << std::endl;
    std::cout << "obj3 value (after assignment): " << obj3.value << std::endl;

    return 0;
}
