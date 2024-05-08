#include<iostream>
using namespace std;

class myVector {
private:
    int* arr;
    int size;
public:
    myVector(int size) {
        if (size < 0) {
            cout << "Size must be a positive Integer" << endl;
            return;
        }
        this->size = size;
        this->arr = new int[size];
    }

    ~myVector() {
        delete[] arr;
        cout << "Deleting Vector" << endl;
    }

    myVector multiply(int scalar) {
        for (int i = 0; i < this->size; i++) {
            this->arr[i] *= scalar;
        }
        return *this;
    }

    myVector operator* (int scalar) {
        return multiply(scalar);
    }

    int& operator[] (int index) {
        if (index >= this->size) {
            cout << "out Of index" << endl;
            throw "out Of index";
        }
        else {
            return this->arr[index];

        }

    }

    void show() {
        for (int i = 0; i < this->size; i++) {
            cout << this->arr[i] << ", ";
        }
        cout << endl;

    }

};

int main() {
    int size;
    cout << "Enter size of vector: ";
    cin >> size;
    myVector vec(size);

    int choice;
    do {
        cout << "\nMenu:\n1. Multiply vector by scalar\n2. Access element\n3. Set Value\n4. Show vector\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int scalar;
            cout << "Enter scalar value: ";
            cin >> scalar;
            vec = vec * scalar;
            cout << "Vector multiplied by " << scalar << ":" << endl;
            vec.show();
            break;
        }
        case 2: {
            int index;
            cout << "Enter index to access: ";
            cin >> index;
            try {
                cout << "Element at index " << index << ": " << vec[index] << endl;
            }
            catch (...) {
                // Exception handled
            }
            break;
        }
        case 3: {
            int index, value;
            cout << "Enter index to set: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;
            vec[index] = value;
            cout << "Value set at index " << index << endl;
            break;
        }
        case 4: {
            cout << "Vector elements: ";
            vec.show();
            break;
        }
        case 5: {
            cout << "Exiting..." << endl;
            break;
        }
        default: {
            cout << "Invalid choice! Please enter a valid option." << endl;
            break;
        }
        }
    } while (choice != 5);

    return 0;
}