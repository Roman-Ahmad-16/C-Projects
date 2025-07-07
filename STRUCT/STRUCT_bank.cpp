//Create a BankAccount struct with fields for account holder name, account number, and balance. Use constructor to initialize. Add a function to:
//Deposit amount
//Withdraw amount
//Display balance

#include<iostream>
using namespace std;
struct BankAccount
{
	string account_holder_name;
	int account_number;
	int balance;
	
		 BankAccount(string a , int b , int c)
		 {
		 	account_holder_name=a;
		 	account_number=b;
		 	balance=c;
		 }
		 
	display_info(){
	    cout << "\n--- Account Info ---\n";
		cout<<"NAME : "<<account_holder_name<<endl;
		cout<<"ACCOUNT NUMBER : "<<account_number<<endl;
		cout<<"BALANCE : "<<balance<<endl;
	}
	
	Deposit_amount(float amount){
		if(amount>0){
			balance+=amount;
            cout << "Deposited Amount : " << amount << endl;
		}else{
			cout<<"AMOUNT IS NOT DEPOSITED"<<endl;
		}
	}
	
	Withdraw_amount(float amount){
		if(amount<=balance && amount>0){
			balance-=amount;
            cout << "Withdrawn Amount: " << amount << endl;
		}else{
			cout<<"Invalid or insufficient balance for withdrawal!"<<endl;
		}
	}
};

int main(){
	
	 BankAccount BA("ROMAN" , 31933, 5000);
	 
	 BA.display_info();
	 BA.Deposit_amount(5000);
	 BA.Withdraw_amount(2000);
	 BA.display_info();


	return 0;	 
}
