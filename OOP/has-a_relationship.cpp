#include <iostream>
using namespace std;
// Account class
class Account
{
private:
    int accountNumber;
    double balance;

public:
    // Constructor
    Account()
    {
        accountNumber = 0;
        balance = 0.0;
    }

    // Set account details
    void setAccount(int accNo, double bal)
    {
        accountNumber = accNo;
        balance = bal;
    }
    // Display account details
    void display()
    {
        cout << "Account Number: " << accountNumber
             << ", Balance: $" << balance << endl;
    }
    // Destructor
};
class Bank
{
private:
    string bankName;
    Account accounts[5];
    int count;

public:
    Bank(string name, int accNos[], double balances[], int n)
    {
        bankName = name;
        count = 0;
        for (int i = 0; i < n && i < 5; i++)
        {
            accounts[count++].setAccount(accNos[i], balances[i]);
        }
    }
    void displayAccounts()
    {

        for (int i = 0; i < count; i++)
        {
            accounts[i].display();
        }
    }
};
int main()
{
    int accNos[] = {101, 102};
    double balances[] = {5000, 12000};

    Bank bank("ABC Bank", accNos, balances, 2);
    bank.displayAccounts();
    return 0;
}