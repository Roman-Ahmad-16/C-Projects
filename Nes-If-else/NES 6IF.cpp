#include<iostream>
using namespace std;
int main (){
	
//	Write a program to check if a person is eligible to vote. A person is eligible if:
//
//Their age is 18 or older
	
	int age;
	cout<<"ENTER YOUR AGE TO CHECK ELIGIBILITY"<<endl;
	cin>>age;
	
	if(age>=18){
		
		        if(age<18){
		        	cout<<"YOU ARE NOT ELIGIBLE"<<endl;
				}else{
					cout<<"YOU ARE ELIGIBLE"<<endl;
				}
	}else{
		cout<<"YOU ARE NOT ELIGIBLE"<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
