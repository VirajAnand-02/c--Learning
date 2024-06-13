#include<iostream>
#include<vector>
using namespace std;

class MyVector {
private:
    vector<float> data;
public:
    MyVector(int initialSize = 0, float defaultValue = 0.0) {
        data = vector<float>(initialSize, defaultValue);
    }
    void modifyElement(int index, float value) {
        if (index >= 0 && index < data.size()) {
            data[index] = value;
        } else {
            cout << "Index out of range." << endl;
        }
    }
    void multiplyByScalar(float scalar) {
        for (int i = 0; i < data.size(); ++i) {
            data[i] *= scalar;
        }
    }
    void displayVector() {
        cout << "(";
        for (int i = 0; i < data.size(); ++i) {
            cout << data[i];
            if (i < data.size() - 1) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }
};


int main() {
    MyVector vec;
    int choice, index, initialSize;
    float value, scalar;
    cout << "Enter initial size of the vector: ";
    cin >> initialSize;
    vec = MyVector(initialSize);
    do {
        cout << "\nMenu:\n";
        cout << "1. Modify Element\n";
        cout << "2. Multiply by Scalar\n";
        cout << "3. Display Vector\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter index and value to modify: ";
                cin >> index >> value;
                vec.modifyElement(index, value);
                break;
            case 2:
                cout << "Enter scalar value to multiply: ";
                cin >> scalar;
                vec.multiplyByScalar(scalar);
                break;
            case 3:
                vec.displayVector();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}
