#include<iostream>
using namespace std;

class Account {
public:
    static int id;

    string name;
    int accNum;
    enum accType { saving, current, FixedDeposite } typeOfAcc;
    double balance;

    Account(string name, accType typeOfAcc, double balance) {
        this->name = name;
        this->accNum = ++Account::id;
        this->typeOfAcc = typeOfAcc;
        this->balance = balance;
        cout << "New Account created for " << this->name << " With Acc Num: " << this->accNum;
    }

    double deposite(double amount) {
        this->balance += amount;
        return this->balance;
    }

    double withdraw(double amount) {
        if (amount < this->balance) {
            this->balance -= amount;
            return this->balance;
        }
        cout << "You dont have enough Balance !!!" << endl;
        return -1;
    }

    void display() {
        cout << "===================================" << endl;
        cout << "ACCOUNT DETAILS" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Account Number: " << this->accNum << endl;
        cout << "Account Type: " << this->typeOfAcc << endl;
        cout << "Balance: " << this->balance << endl;
        cout << "===================================" << endl;
    }

};

int Account::id = 0;

int main() {
    Account::id = 0;
    Account* account = nullptr;
    int choice;
    string name;
    double amount;
    Account::accType type;
    int typeInput;

    while (true) {
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Account\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Name: ";
            cin >> name;
            cout << "Select Account Type (0 for saving, 1 for current, 2 for Fixed Deposit): ";
            cin >> typeInput;
            type = static_cast<Account::accType>(typeInput);
            cout << "Enter Initial Balance: ";
            cin >> amount;
            account = new Account(name, type, amount);
            break;
        case 2:
            if (account) {
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                if (amount < 0) {
                    cout << "Amount Must be positive" << endl;
                    break;
                }
                account->deposite(amount);
            }
            else {
                cout << "Please create an account first.\n";
            }
            break;
        case 3:
            if (account) {
                cout << "Enter Withdraw Amount: ";
                cin >> amount;
                if (account->withdraw(amount) == -1) {
                    cout << "Insufficient funds.\n";
                }
            }
            else {
                cout << "Please create an account first.\n";
            }
            break;
        case 4:
            if (account) {
                account->display();
            }
            else {
                cout << "No account to display.\n";
            }
            break;
        case 5:
            cout << "Exiting program.\n";
            delete account;
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}