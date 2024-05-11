#include<iostream>
using namespace std;

class AddMult {
private:
    int m_val;
public:
    AddMult(int a, int b) {
        this->m_val = a + b;
    }
    AddMult(int a, int b, bool mult) {
        if (mult) {
            this->m_val = a * b;
        }
        else {
            this->m_val = a + b;
        }
    }
    void display() const {
        cout << "The result is: " << m_val << endl;
    }
};

int main() {
    // Using the addition constructor
    AddMult obj1(5, 3);
    obj1.display();

    // Using the constructor that can also multiply
    AddMult obj2(5, 3, true);
    obj2.display();

    // Using the constructor for addition explicitly by passing false
    AddMult obj3(5, 3, false);
    obj3.display();

    return 0;
}