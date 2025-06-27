#include<iostream>
using namespace std;
int main(){
	
	int num1, num2, num3;
	cout<<" ENTER THE THREE NUM TO FIND THE GREATEST NUMBER "<<endl;
	cin>>num1>>num2>>num3;
	
	
	
	if(num1>=num2&& num1>=num3){
		
		cout<<num1<<"is the largest num";
	}
	else if(num2>=num1 && num2>=num3){
		
		cout<<num2<<" is the greatest number ";
	}
	else if (num3>=num1 && num3>=num2) {
		
		cout<<num3<<" is the largest num";
		
		return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
