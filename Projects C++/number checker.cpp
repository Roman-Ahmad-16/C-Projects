#include<iostream>
using namespace std;
int main(){
	
	int number;
	
	char ch;
	cout<<"Enter 'S' or 's' To Start a program"<<endl;
	cout<<"Enter 'E' or 'e' to end a program"<<endl;
	cin>>ch;
	
	while(ch!='s' && ch!='S' && ch!='e' && ch!='E'){
		  cout<<"Invaild Character :: Enter a correct character = ";
		  cin>>ch;
	}
	if(ch=='e' || ch=='E'){
		cout<<"Program is end "<<endl;
		return 0;
	}
	
	while(true){
		  
		  cout<<"1.Check Even Number"<<endl;
		  cout<<"2.Check Odd Number"<<endl;
		  cout<<"3.Check Integer "<<endl;
		  cout<<"4.Check Real Number"<<endl;
		  cout<<"5.Check Prime Number"<<endl;
		  cout<<"0.Enter 0 to exist a program"<<endl;
		  
		  int choice;
		  cout<<"Select any number = ";
		  cin>>choice;
		  
		  if(choice==0){
		  	cout<<"Program is end "<<endl;
		  	break;
		  	
		  }else if (choice==1){
		  	cout<<"Enter a number to check = ";
		  	cin>>number;
		  	if(number%2==0){
		  	cout<<number<<" is even number"<<endl;
			}else {
			cout<<number<<" is not even number"<<endl;
			}
			
			
		  }else if(choice==2){
		  	cout<<"Enter a number to check = ";
		  	cin>>number;
		  	if(number%2!=0){
		  	cout<<number<<" is odd number"<<endl;
			}else{
			cout<<number<<" is not odd number"<<endl;
			}
			
			
		  }else if(choice==3){
		  	cout<<"Enter a number to check = ";
		  	cin>>number;
		  	cout<<number<<" is a integer"<<endl;
		  	
		  	
		  }else if(choice==4){
		  	cout<<"Enter a number to check = ";
		  	cin>>number;
		  	cout<<number<<" is a real number"<<endl;
		  	
		  	
		  }else if(choice==5){
		  	cout<<"Enter a number to check = ";
		  	cin>>number;
		  	
		  	if(number<=1){
		  	cout<<number<<" is not prime number"<<endl;
			}else{
			int i=2;
			bool prime=true;
			while(i*i<=number){
				if(number%i==0){
				prime=false;
				break;
				}
				i++;
			}
			if(prime){
				cout<<number<<" is a prime number"<<endl;
			}else{
				cout<<number<<" is not a prime number"<<endl;
			}
						
			}
		  	
	
		  }else {
			    cout << "Invalid Input. Please Enter a number from the given Menu." << endl;
		  }




	}
		
	return 0;
}
