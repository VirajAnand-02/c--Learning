#include<iostream>
#include <math.h>
using namespace std;

class Account {
public:
    string name;
    int accountNumber;
    string acc_type = "None";
    double balance = 0;

    // accept deposite and update balance
    void deposite(double amount) {
        double tmp = balance + amount;
        if (tmp > balance) {
            balance = tmp;
            cout << "Deposite sucessfull !" << endl;
        }
        else {
            cout << "Deposite UNSUCESSFULL !!!" << endl;
        }
    }

    // Withdrawl feature | and update balance
    double withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance" << endl;
            return 0.0f;
        }
        balance -= amount;
        cout << "Withdrawl of " << amount << " sucessfull" << endl;
        postWithdrawl();
        return amount;
    }

protected:
    virtual void postWithdrawl() {
        cout << "Account balance: " << balance << endl;
    }
};


class Check {

};


class curr_acct : public Account {
private:
    bool warned = false;
    // minimum balance
    void minBalance() {
        cout << "Account balance: " << balance << endl;
        if (balance < minBalanceRequired) {
            cout << "Your balance is less than minimum required for a Current Account\nplease keep balance above minimum balance or penelty/mentainance charge of 100₹ will be imposed." << endl;
            if (warned) {
                penelty();
            }
            warned = true;
        }
        else {
            warned = false;
        }
    }
    // check min balance and impose penalty | service charge
    void penelty() {
        if (balance < minBalanceRequired) {
            balance -= 100;
            cout << "penelty imposed !!! \n 100₹ have been deducted form your account. \nTo prevent further penelties please mantain your minimum balance above " << minBalanceRequired << " ₹." << endl;
        }
    }

public:
    curr_acct() {
        acc_type = "current";
    }

    double minBalanceRequired = 1000.00;

    // checkbook feature
    virtual void checkInto(curr_acct checkerAccount, Check check) {

    }


protected:
    void postWithdrawl() override {
        minBalance();
    }
};


class sav_acct : public Account {
private:
    float intrestRater = 0.7;
    float n_compoundsPerYear = 4;
    double compoundIntrest(float time_year = 1.0f) {
        return balance * pow((1 + intrestRater / n_compoundsPerYear), (n_compoundsPerYear * time_year));
    }

public:
    void setIntrestRate(float intrest) {
        intrestRater = intrest;
    }
    // Compound intrest feature 

    // compute and deposite intrest | DONE CALCULATION |
    void depositeIntrest() {
        balance = compoundIntrest();
    }

    sav_acct() {
        acc_type = "current";
    }

};

int main() {

    // Create a current account instance
    curr_acct currentAccount;
    cout << "Creating a current account..." << endl;

    // Deposit some money
    cout << "Depositing 1500 into current account..." << endl;
    currentAccount.deposite(1500);

    // Attempt to withdraw more than the balance to test the insufficient funds message
    cout << "Attempting to withdraw 1600 from current account..." << endl;
    currentAccount.withdraw(1600);

    // Withdraw an amount within the balance to check penalties
    cout << "Withdrawing 600 from current account..." << endl;
    currentAccount.withdraw(600);

    // Withdraw to trigger minimum balance penalty
    cout << "Withdrawing 500 from current account..." << endl;
    currentAccount.withdraw(500);

    // Create a savings account instance
    sav_acct savingsAccount;
    cout << "\nCreating a savings account..." << endl;

    // Demonstrate deposit for savings account
    cout << "Depositing 2000 into savings account..." << endl;
    savingsAccount.deposite(2000);

    // Withdraw from savings account
    cout << "Withdrawing 500 from savings account..." << endl;
    savingsAccount.withdraw(500);

    // Note: To fully demonstrate the features of `sav_acct`, you'd need to implement
    // and call methods related to interest calculation and application, which are
    // not currently defined in the `sav_acct` class code provided.

    return 0;


}