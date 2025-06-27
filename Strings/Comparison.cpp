#include<iostream>
using namespace std;
int main(){
	
	
	char str1[20];
	char str2[20];
	
	cout<<"ENTER A FIRST STRING = ";
	cin.getline(str1,20);
	
	cout<<"ENTER A SECOND STRING = ";
	cin.getline(str2,20);
	
	int i=0;
	bool Equal=true;
	
	while (str1[i]!='\0' && str2[i]!='\0'){
		
		if(str1[i]!=str2[i]){
				Equal=false;
				break;
		}
		i++;
	}
	
	if( Equal && str1[i]==str2[i]){
		cout<<"Strings are Equal"<<endl;
	}
	else if (str1[i]>str2[i]){
		cout<<"STRING ONE IS GREATER "<<endl;
	}
	else {
		cout<<"STRING TWO IS GREATER"<<endl;
	}
	
	
	
	return 0;
}
