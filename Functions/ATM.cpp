#include<iostream>
using namespace std;


  void displayMenu(){
  	
  		cout<<"1.CHECK BALANCE"<<endl;
		cout<<"2.WITHDRAW MONEY"<<endl;
		cout<<"3.DEPOSIT MONEY"<<endl;
		cout<<"4.EXIST"<<endl;
		
  }
  
  					void checkBalance(int &balance){
  								
  					cout<<" YOUR CURRENT BALANCE = "<<balance<<endl; 
					  	             
				    }
			
				  				  
		void withdrawn(int withdraw , int &balance){
			  				   
		cout<<"Enter a amount to withdraw = ";
		cin>>withdraw;
		if(balance<withdraw){
		cout<<"Insufficient Funds"<<endl;			          
		}else{
		balance-=withdraw;
		cout<<"Your current balance is = "<<balance<<endl;
		  }
		}
  				
  
  
  				      void deposit(int amount , int &balance){
  					
			          cout<<"Enter amount to deposit = "<<endl;
			          cin>>amount;
			          balance+=amount;
			          cout<<"Your current balance is = "<<balance<<endl;
			          
		              }

  
  

  int main(){
   
   int balance=5000;
   int withdraw;
   int amount;
   int choice;
   
   while(true){
   	  	
   	displayMenu();
   	  cout<<"SELECT A NUMBER = ";
   	  cin>>choice;
       
       
      if(choice==1){
      	checkBalance(balance);
	  } 
	  else if (choice==2){
	  	withdrawn(withdraw , balance);
	  }
	  else if(choice==3){
	  	deposit(amount , balance);
	  }
	  else if(choice==4){
	  	cout<<"Program is exist"<<endl;
	  	return 0;
	  }
	  else {
	  	cout<<"Enter a valid number"<<endl;
	  }
     
    }
	return 0;
}


