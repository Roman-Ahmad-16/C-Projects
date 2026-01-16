#include <iostream>
using namespace std;
class BankAccount
{
private:
    int balance;

public:
    BankAccount(int b = 0)
    {
        balance = b;
    }

    BankAccount operator+(int amount)
    {
        BankAccount temp;
        temp.balance = balance + amount;
        return temp;
    }

    BankAccount operator-(int amount)
    {
        BankAccount temp;
        if (amount <= balance)
            temp.balance = balance - amount;
        else
        {
            cout << "Insufficient balance!" << endl;
            temp.balance = balance;
        }
        return temp;
    }
    void display()
    {
        cout << "Balance: " << balance << endl;
    }
};
int main()
{
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;
    BankAccount accounts[n];

    for (int i = 0; i < n; i++)
    {
        int bal;
        cout << "Enter initial balance for Account " << i << ": ";
        cin >> bal;
        accounts[i] = BankAccount(bal);
    }
    int accNo, amount;

    cout << "\nEnter account number for deposit: ";
    cin >> accNo;
    cout << "Enter deposit amount: ";
    cin >> amount;
    if (accNo >= 0 && accNo < n)
    {
        accounts[accNo] = accounts[accNo] + amount;
        cout << "After deposit ";
        accounts[accNo].display();
    }
    else
        cout << "Invalid account number!" << endl;

    cout << "\nEnter account number for withdrawal: ";
    cin >> accNo;
    cout << "Enter withdrawal amount: ";
    cin >> amount;
    if (accNo >= 0 && accNo < n)
    {
        accounts[accNo] = accounts[accNo] - amount;
        cout << "After withdrawal ";
        accounts[accNo].display();
    }
    else
        cout << "Invalid account number!" << endl;
    return 0;
}