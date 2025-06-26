#include<iostream>
using namespace std;
int main(){
	
	int balance=5000;
	int withdraw;
	int amount;
	
	while (true){
		
		cout<<"1.CHECK BALANCE"<<endl;
		cout<<"2.WITHDRAW MONEY"<<endl;
		cout<<"3.DEPOSIT MONEY"<<endl;
		cout<<"4.EXIST"<<endl;
		
		int choice;
		cout<<"Select a number = ";
		cin>>choice;
		
		
		if(choice==1){
			          cout<<"Your current balance is = "<<balance<<endl;
			          
		}else if (choice==2){
			          cout<<"Enter a amount to withdraw = ";
			          cin>>withdraw;
			          if(balance<withdraw){
			          cout<<"Insufficient Funds"<<endl;			          
					  }else{
					  	balance-=withdraw;
					  	cout<<"Your current balance is = "<<balance<<endl;
					  }
					  
		}else if (choice==3){
			          cout<<"Enter amount to deposit = "<<endl;
			          cin>>amount;
			          balance+=amount;
			          cout<<"Your current balance is = "<<balance<<endl;
			          
		}else if(choice==4){
			          cout<<"SThanks for Using our ATM"<<endl;
			          break;
		}else {
            cout << "Invalid Input. Please Enter a number from the given Menu." << endl;
            break;
        }
		


	
	}
	
	return 0;
}
