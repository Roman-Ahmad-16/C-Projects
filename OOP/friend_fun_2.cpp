#include<iostream>
using namespace std;

class Account {
    private:
        int balance;
    public:
        Account(int b){
            balance = b ;
        }
    friend void showBalance(Account b);
};

void showBalance(Account a)
{
    cout<<"Balance is : "<<a.balance;
}
int main(){

    Account acc(5000);
    showBalance(acc);
    
    return 0;
}