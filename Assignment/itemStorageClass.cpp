#include <iostream>
#include <string>

using namespace std;

class Item {
private:
    string itemCode;
    double itemPrice;

public:
    // Constructor
    Item(string code, double price) : itemCode(code), itemPrice(price) {}

    // Getter methods
    string getItemCode() const {
        return itemCode;
    }

    double getItemPrice() const {
        return itemPrice;
    }

    // Setter methods
    void setItemCode(string code) {
        itemCode = code;
    }

    void setItemPrice(double price) {
        itemPrice = price;
    }

    // Method to update both code and price
    void updateItem(string code, double price) {
        itemCode = code;
        itemPrice = price;
    }

    // Display method
    void display() const {
        cout << "Item Code: " << itemCode << ", Item Price: $" << itemPrice << endl;
    }
};

int main() {
    // Creating an item object
    Item item("A001", 10.99);

    // Displaying initial values
    cout << "Initial Item Details:" << endl;
    item.display();

    // Updating item code and price
    item.updateItem("B002", 15.99);

    // Displaying updated values
    cout << "\nUpdated Item Details:" << endl;
    item.display();

    return 0;
}
