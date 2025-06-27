#include<iostream>
using namespace std;
int main(){
	
	int num;
	cout<<"ENTER A NUMBER TO CHECK = ";
	cin>>num;
	
	int originalnum=num;
	
	int remainder;
	int result=0;
	
	while(originalnum!=0){
		
		remainder=originalnum%10;
		result+=remainder*remainder*remainder;
		originalnum/=10;
	}
	
	if (result==num){
		cout<<"armstrong"<<endl;
	}
	else {
		cout<<"not ";
	}
	return 0;
}
