//Write a program to check if a number is positive, negative, or zero using nested if.

#include<iostream>
using namespace std;
int main (){
	
	int a;
	cout<<"ENTER A NUMBER"<<endl;
	cin>>a;
	
	if (a>0){
		 
		     if (a<0){
		     	cout<<"number is neagtive"<<endl;
			 } 
			 
			 else {
			 	cout<<"number is positive "<<endl;
			 }
			 
			} 
	else {
		
		    if(a==0){
		    cout<<"Equal to zero"<<endl;
		    
	        } else {
	        	cout<<"number is neagtive"<<endl;
			}
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}

