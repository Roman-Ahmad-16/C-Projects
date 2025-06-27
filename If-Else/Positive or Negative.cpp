#include <iostream>
using namespace std;
int main(){
	
//	Check Positive/Negative
//Input a number and check whether it's positive, negative, or zero.
//Hint: Use if-else.
	
	int number ;
	cout<<"ENTER A NUMBER TO CHECK WETHER IT IS POSITIVE OR NEGATIVE OR ZERO"<<endl;
	cin>>number;
	
	if (number>0){
		cout<<number<<" IS POSITIVE NUMBER "<<endl;
	}
	else if (number<0){
		cout<<number<<"IS THE NEGATIVE NUMBER "<<endl;
	}
	else {
		cout<<number<<"IS ZERO "<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
