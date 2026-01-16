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
        temp.balance = balance - amount;
        return temp;
    }

    void operator=(BankAccount obj)
    {
        balance = obj.balance;
    }

    bool operator>=(BankAccount obj)
    {
        return balance >= obj.balance;
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
    BankAccount *acc[n];

    for (int i = 0; i < n; i++)
    {
        int bal;
        cout << "Enter initial balance for Account " << i + 1 << ": ";
        cin >> bal;
        acc[i] = new BankAccount(bal);
    }
    int dep;
    cout << "\nEnter deposit amount for Account 1: ";
    cin >> dep;
    *acc[0] = *acc[0] + dep;
    int wd;
    cout << "Enter withdrawal amount for Account 2: ";
    cin >> wd;
    *acc[1] = *acc[1] - wd;
    cout << "\nAccount Details:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Account " << i + 1 << " ";
        acc[i]->display();
    }
    if (*acc[0] >= *acc[1])
        cout << "\nAccount 1 has greater or equal balance than Account 2";
    else
        cout << "\nAccount 2 has greater balance";
    for (int i = 0; i < n; i++)
    {
        delete acc[i];
    }
    return 0;
}