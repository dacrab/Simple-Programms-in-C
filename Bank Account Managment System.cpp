#include <iostream>
#include <map>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNumber) : accountNumber(accNumber), balance(0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
        } else {
            cout << "Error: Invalid amount for deposit!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << endl;
            } else {
                cout << "Error: Insufficient balance!" << endl;
            }
        } else {
            cout << "Error: Invalid amount for withdrawal!" << endl;
        }
    }

    void displayBalance() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    map<string, BankAccount> accounts;

    accounts["123456"] = BankAccount("123456");
    accounts["789012"] = BankAccount("789012");

    accounts["123456"].deposit(1000);
    accounts["123456"].withdraw(200);
    accounts["123456"].displayBalance();

    accounts["789012"].deposit(500);
    accounts["789012"].withdraw(1000); // Should display error
    accounts["789012"].displayBalance();

    return 0;
}
