#include<iostream>
using namespace std;
int main(){
	
	char str[20];
	int count=0;
	
	cout<<"ENTER A STRING "<<endl;
	cin.getline(str,20);
	
	for(int i=0; str[i]!='\0'; i++){
		count++;	
	}
	
	cout<<"THE SIZE OF THE ARRAY = "<<count<<endl;
	
	return 0;
}
