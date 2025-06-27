#include<iostream>
using namespace std;

int factorial(int num , int a=1 ){
	
		for( int i=1; i<=num; i++){
		a*=i;
	}
	return a;
}

int main(){
	
	long  int num;
	cout<<"ENTER A NUMBER = ";
	cin>>num;
	
    int a=1;
	
   int result=factorial(num,a);
   cout<<"Factorial  = "<<result<<endl;
	
	
	return 0;
}
