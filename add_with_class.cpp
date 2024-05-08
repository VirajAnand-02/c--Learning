#include<iostream>
using namespace std;

class Number {
private:
    int num;
public:
    int get_data() {
        int num;
        cout << "Enter number : ";
        cin >> num;
        this->num = num;
    }
    int add_data(Number another) {
        return this->num + another.num;
    }
};

int main() {
    Number A, B;
    cout << "Set A : ";
    A.get_data();
    cout << "Set B : ";
    B.get_data();
    cout << "Sum of A and B : " << A.add_data(B) << endl;

}