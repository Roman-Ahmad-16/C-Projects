//Program 5: Factorial of a number


#include<iostream>
using namespace std;
int main(){
	
	
	
	long int a,sum=1;
	cout<<"ENTER A NUMBER = ";
	cin>>a;
	
	for(int b=1;b<=a;b++){
		sum*=b;
	}
	cout<<sum<<endl;
	
	
	
	
	return 0;
}

