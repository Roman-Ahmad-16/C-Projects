#include<iostream>
using namespace std;
 
int call(int num1 , char op , int num2){
	
	if(op=='+'){
		cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1+num2<<endl;
	}
	else if (op=='-'){
		cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1-num2<<endl;
	}
	else if(op=='*'){
		cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1*num2<<endl;
	}
	else if(op=='/'){
		cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1-num2<<endl;
	}
	else{
		cout<<"ENTER A VALID OPERATOR"<<endl;
	}
	
}
int main(){
	
	
	int num1,num2;
	char a;
	
	cout<<" ENTER TWO NUMBERS AND ONE CHARACTER = "<<endl;
	cin>>num1>>a>>num2;
	
	call(num1,a,num2);
	
	
	return 0;
}
