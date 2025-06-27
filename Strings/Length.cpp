#include<iostream>
using namespace std;
int main(){
	
	
	char str[20];
	int length=0;
	
	cout<<"ENTER A STRING "<<endl;
	cin.getline(str,20);
	
	while(str[length]!='\0'){
		length++;
	}
	
	cout<<"LENGTH OF STRING = "<<length<<endl;
	return 0;
}
