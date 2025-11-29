#include <iostream>
using namespace std;
class bankAccount
{
public:
    int balance = 2000;
    void deposit(int a)
    {
        balance += a;
        cout << "Balance is deposit = 1" << balance << endl;
    }

    void withdraw(int a)
    {
        if (balance >= 2)
        {
            balance -= a;
            cout << "Balance is withdraw = " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
};

int main()
{
    bankAccount b;

    int choice;
    cout << "Enter your choice" << endl;
    cout << "1 for deposit /n 2 for withdraw" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        b.deposit(8000);
        break;
    case 2:
        b.withdraw(2000);
        break;
    default:
        cout << "Insufficient amount" << endl;
    }
    return 0;
}