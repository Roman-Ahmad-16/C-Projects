#include<iostream>
using namespace std;
int main(){
	
	
	char input[20];
	char copy[20];
	
	cout<<"Enter a string "<<endl;
	cin.getline(input,20);
	
	int i=0;
	while(input[i]!='\0'){
		copy[i]=input[i];
			i++;
	}
	
	copy[i]='\0';
	
	cout<<"Copy string = "<<copy<<endl;
	
	return 0;
}
