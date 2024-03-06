#include <iostream>
#define MAX_ITEMS 10
using namespace std;

class item {
private:
public:
    string name;
    float price;
    int quantity;

    item(string name = "", float price = 0, int quantity = 1) {
        if (name == "" || price == 0) {
            this->price = 0;
            this->quantity = 0;
            return;
        }
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
};

class ShoppingList {
public:
    item list[MAX_ITEMS];
    int itemsCount = 0;

    void addItem(item item) {
        if (itemsCount < MAX_ITEMS)
            list[++itemsCount] = item;
        else {
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (list[i].name == "") {
                    list[i] = item;
                    return;
                }
            }
            cout << "Max Items reached";
        }
    }

    void deleteItem(int index) {
        list[index] = item(); // empty item
    }

    float totalPrice() {
        float price = 0;
        for (int i = 0;i < MAX_ITEMS; i++) {
            price += list[i].name == "" ? 0 : list[i].price * list[i].quantity;
        }
        return price;
    }

    int totalItems() {
        int items = 0;
        for (int i = 0;i < MAX_ITEMS; i++) {
            items += list[i].quantity;
        }
        return items;
    }

    void printCart() {
        cout << "========================================" << endl;
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (list[i].name == "")
                continue;
            cout << i << ") Item: " << list[i].name << " Price: " << list[i].price << " | Quantity: " << list[i].quantity << " | Total: " << list[i].price * list[i].quantity << endl;
        }
        cout << "========================================" << endl;

    }
};

void menu(ShoppingList list) {
    cout << "Total items : " << list.totalItems() << " | Total cart value: " << list.totalPrice() << endl;
    cout << "------------------------------------------" << endl;
    cout << "1) Add item" << endl;
    cout << "2) Delete item" << endl;
    cout << "3) Show Cart" << endl;
    cout << "4) Exit" << endl;
    cout << "> ";

}

item generateItem() {
    string name;
    cout << "Item name: ";
    cin >> name;

    float price;
    cout << "Item price: ";
    cin >> price;

    int quantity;
    cout << "Item quantity: ";
    cin >> quantity;

    return item(name, price, quantity);
}

int main() {
    ShoppingList List;
    while (true) {
        menu(List);
        int input, itemId;
        cin >> input;

        switch (input) {
        case 1:
            List.addItem(generateItem());
            break;
        case 2:
            cout << "Input item ID: ";
            cin >> itemId;
            List.deleteItem(itemId);
            break;
        case 3:
            List.printCart();
            break;
        case 4:
            cout << "Exitting..." << endl;
            exit(0);
            break;

        default:
            break;
        }
    }


}