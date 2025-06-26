#include <iostream>
#include <vector>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolder = name;
        balance = initialBalance;
    }

    int getAccountNumber() { return accountNumber; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "?? Deposit successful! New balance: $" << balance << endl;
        } else {
            cout << "? Invalid amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "?? Withdrawal successful! New balance: $" << balance << endl;
        } else {
            cout << "? Insufficient funds or invalid amount!" << endl;
        }
    }

    void displayBalance() {
        cout << "?? Account Number: " << accountNumber << ", Holder: " << accountHolder
             << ", Balance: $" << balance << endl;
    }
};

// Global vector to store accounts
vector<BankAccount> accounts;

void createAccount() {
    int accNo;
    string name;
    double initialBalance;
    
    cout << "Enter account number: ";
    cin >> accNo;
    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    accounts.push_back(BankAccount(accNo, name, initialBalance));
    cout << "? Account created successfully!\n";
}

void depositMoney() {
    int accNo;
    double amount;
    cout << "Enter account number: ";
    cin >> accNo;

    for (size_t i = 0; i < accounts.size(); i++) { 
        if (accounts[i].getAccountNumber() == accNo) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            accounts[i].deposit(amount);
            return;
        }
    }
    cout << "? Account not found!\n";
}

void withdrawMoney() {
    int accNo;
    double amount;
    cout << "Enter account number: ";
    cin >> accNo;

    for (size_t i = 0; i < accounts.size(); i++) { 
        if (accounts[i].getAccountNumber() == accNo) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            accounts[i].withdraw(amount);
            return;
        }
    }
    cout << "? Account not found!\n";
}

void checkBalance() {
    int accNo;
    cout << "Enter account number: ";
    cin >> accNo;

    for (size_t i = 0; i < accounts.size(); i++) { 
        if (accounts[i].getAccountNumber() == accNo) {
            accounts[i].displayBalance();
            return;
        }
    }
    cout << "? Account not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n?? --- Bank Management System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                cout << "?? Thank you for using our bank system!\n";
                break;
            default:
                cout << "?? Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

