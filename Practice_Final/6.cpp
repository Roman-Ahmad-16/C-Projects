#include<iostream>
using namespace std;

struct Bank_Account
{
	string account_holder_name;
	int account_number;
	int balance;
	
		Bank_Account(string a , int b , int c)
		{
			account_holder_name=a;
			account_number=b;
			balance=c;
		}
	void display_info()
	{
		cout<<"NAME = "<<account_holder_name<<endl;
		cout<<"account_number = "<<account_number<<endl;
		cout<<"balance = "<<balance<<endl;
	}
		
		void Deposit_Amount(float amount)
		{
			if(amount > 0 )
			{
				balance+=amount;
				cout << "Deposited Amount : " << amount << endl;
			}
			else 
			{
				cout<<"AMOUNT IS NOT DEPOSITED"<<endl;

			}
		}
		
	void Withdraw_Amount(float amount)
	{
		if(amount<balance && amount>=0)
		{
			balance-=amount;
			cout << "Withdrawn Amount: " << amount << endl;
		}
		else 
		{
			cout<<"AMOUNT IS NOT DEPOSITED"<<endl;
		}
	}
		
};


int main()
{
	Bank_Account bank("Roman" , 295 , 50000);
	
	bank.display_info();
	bank.Deposit_Amount(1000);
	bank.Withdraw_Amount(2000);
	bank.display_info();
	
	return 0;
}
