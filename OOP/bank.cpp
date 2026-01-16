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
    int initialBalance, depositAmount, withdrawAmount;

    cout << "Enter initial balance: ";
    cin >> initialBalance;
    BankAccount accA(initialBalance);
    BankAccount accB;
    // Deposit
    cout << "Enter deposit amount: ";
    cin >> depositAmount;
    accA = accA + depositAmount;
    cout << "After Deposit ";
    accA.display();

    cout << "Enter withdrawal amount: ";
    cin >> withdrawAmount;
    accA = accA - withdrawAmount;
    cout << "After Withdrawal ";
    accA.display();

    accB = accA;
    cout << "Account B ";
    accB.display();

    if (accA >= accB)
        cout << "Accoun A has greater or equal balance than Account B" << endl;
    else
        cout << "Account B has greater balance" << endl;
    return 0;
}