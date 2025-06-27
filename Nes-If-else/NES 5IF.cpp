#include<iostream>
using namespace std;
int main(){
	
	
	
//	Write a program to check if a triangle is valid based on the sides entered by the user. A triangle is
//	valid if the sum of any two sides is greater than the third side.
	
	int a,b,c;
	cout<<"ENTER YOUR NUMBERS:"<<endl;
	cin>>a>>b>>c;
	
	if(a+b>c){
		      
		      if(a+c>b){
		      	cout<<"TRIANGLE IS VALID"<<endl;
			  }else{
			  	cout<<"TRIANGLE IS NOT VALID"<<endl;
			  }
	}else{
		
		  if(b+c>a){
		  	cout<<"TRIANGLE IS VALID"<<endl;
		  }else{
		  	cout<<"TRIANGLE IS NOT VALID"<<endl;
		  }
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
