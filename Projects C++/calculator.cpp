#include<iostream>
using namespace std;
int main(){
	
	double num1;
	double num2;
	
    cout << "Welcome to the Simple Calculator!" << endl;
	
	while(true){
		
		cout<<"1.Addition"<<endl;
		cout<<"2.Subtraction"<<endl;
		cout<<"3.Multiplication"<<endl;
		cout<<"4.Division"<<endl;
		cout<<"0.Press 0 to exist a program "<<endl;
		
		int choice;
		cout<<"Select any number = ";
		cin>>choice;
		
		if(choice==1){
			
	
	            cout<<"Enter first number = ";
	            cin>>num1;
	            cout<<"Enter second number = ";
	            cin>>num2;
	
		cout<<"Addition of numbers is equal :: "<<num1+num2<<endl;
		}else if(choice==2){
			
			
			    cout<<"Enter first number = ";
	            cin>>num1;
	            cout<<"Enter second number = ";
	            cin>>num2;
	            
		cout<<"Subtraction of numbers is equal :: "<<num1-num2<<endl;
		}else if(choice==3){
			
			    cout<<"Enter first number = ";
	            cin>>num1;
	            cout<<"Enter second number = ";
	            cin>>num2;
	            
	            
		cout<<"Multiplication of numbers is equal :: "<<num1*num2<<endl;
		}else if(choice==4){
			
			    cout<<"Enter first number = ";
	            cin>>num1;
	            cout<<"Enter second number = ";
	            cin>>num2;
	            
	            if(num2!=0){	            	
	 	        cout<<"Division of numbers is equal :: "<<num1/num2<<endl;
				}else{
				cout<<"Division by zero is not allowed"<<endl;
				}
	            
		}else if(choice==0){
			cout<<"Program is end "<<endl;
			break;
			
			
		}else {
			cout<<"Invalid number "<<endl;
		}
		
		
		
		
	}
	
	return 0;
}
