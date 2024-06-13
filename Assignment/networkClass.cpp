#include<iostream>
using namespace std;

class Person {
public:
    string name;
    int code;
};

class Admin : public Person {
public:
    string experience;
};

class Account {
public:
    int pay;
};

class Master : public Account, public Admin {
public:
    void display() {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
        cout << "Pay: " << pay << endl;
        cout << "Experience: " << experience << endl;
    }
};

int main() {
    Master m;
    m.name = "John Doe";
    m.code = 1234;
    m.pay = 5000;
    m.experience = "5 years";

    cout << "Displaying Master Information:" << endl;
    m.display();

    // Update information
    m.pay = 6000;
    m.experience = "6 years";

    cout << "\nUpdated Master Information:" << endl;
    m.display();

    return 0;
}
