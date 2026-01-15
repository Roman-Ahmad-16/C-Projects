#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double b = 0)
    {
        balance = b;
    }

    void showBalance() const
    {
        cout << "PKR " << balance << endl;
    }

    BankAccount operator+(double amount)
    {
        return BankAccount(balance + amount);
    }

    BankAccount operator-(double amount)
    {
        if (amount > balance)
        {
            cout << "Error: Insufficient funds!" << endl;
            return *this;
        }
        return BankAccount(balance - amount);
    }

    void operator=(const BankAccount &other)
    {
        balance = other.balance;
        cout << ">> Assignment Operator Called. Balance copied." << endl;
    }

    bool operator>=(const BankAccount &other)
    {
        if (balance >= other.balance)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    cout << "--- Creating Account 1 ---" << endl;
    BankAccount customer1(1000.0);
    cout << "Customer 1 ";
    customer1.showBalance();

    cout << "\n--- Depositing 500 into Account 1 ---" << endl;
    customer1 = customer1 + 500.0;
    cout << "New Balance: ";
    customer1.showBalance();

    cout << "\n--- Withdrawing 200 from Account 1 ---" << endl;
    customer1 = customer1 - 200.0;
    cout << "New Balance: ";
    customer1.showBalance();

    cout << "\n--- Creating Account 2 and Assigning Account 1's balance to it ---" << endl;
    BankAccount customer2;
    customer2 = customer1;
    cout << "Customer 2 Balance: ";
    customer2.showBalance();

    cout << "\n--- Comparing Account 1 and Account 2 ---" << endl;
    customer2 = customer2 - 100;

    cout << "Customer 1: ";
    customer1.showBalance();
    cout << "Customer 2: ";
    customer2.showBalance();

    if (customer1 >= customer2)
    {
        cout << "Result: Customer 1 is richer or equal to Customer 2." << endl;
    }
    else
    {
        cout << "Result: Customer 2 is richer." << endl;
    }

    return 0;
}