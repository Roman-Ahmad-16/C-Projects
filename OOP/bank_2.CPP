#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountHolder;
    double balance;

    static double interestRate;
    static double totalCashInBank;

public:
    BankAccount(string name, double bal)
    {
        accountHolder = name;
        balance = bal;
        totalCashInBank += bal;
    }

    void displayAccount()
    {
        cout << "Account: " << accountHolder << " | Balance: " << balance
             << " | Current Interest Rate: " << interestRate << "%" << endl;
    }

    static void setInterestRate(double newRate)
    {
        interestRate = newRate;
        cout << "\n[NOTICE] Bank Manager changed Interest Rate to: " << interestRate << "%" << endl;
    }

    static void showBankStatus()
    {
        cout << ">>> Total Cash in Bank: " << totalCashInBank << endl;
    }
};

double BankAccount::interestRate = 5.0;
double BankAccount::totalCashInBank = 0.0;

int main()
{
    BankAccount p1("Ali", 1000);
    BankAccount p2("Sara", 5000);

    p1.displayAccount();
    p2.displayAccount();

    BankAccount::showBankStatus();

    BankAccount::setInterestRate(8.5);

    cout << "After update:" << endl;
    p1.displayAccount();
    p2.displayAccount();

    return 0;
}