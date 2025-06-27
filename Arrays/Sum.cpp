#include<iostream>
using namespace std;
int main(){
	
//	WRITE A PROGRAM THAT INPUTS 5 VALUES FROM USER STORE IN 
//  ARRAY AND DISPLAY THE SUM AND AVERAGE OF THESE VALUES.
	
	
	int a[5];
	int sum=0;
	int avg=0;

	for( int i=0; i<5; i++){
		cout<<"ENTER VALUES = ";
		cin>>a[i];
		sum+=a[i];
	}	
	
	cout<<"SUM OF THESE VALUES = "<<sum<<endl;
	
	
	avg=sum/5;
	cout<<"AVERAGE OF THESE VALUES = "<<avg<<endl;

	return 0;
}
