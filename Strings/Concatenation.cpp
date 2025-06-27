#include<iostream>
using namespace std; 
int main(){
	
	char str1[30];
	char str2[30];
	
	cout<<"Enter a first string "<<endl;
	cin.getline(str1,30);
	
	cout<<"Enter a second string "<<endl;
	cin.getline(str2,30);
	
	int i=0;
	while(str1[i]!='\0'){
		i++;
	}
	

	int j;
	while(str2[j]!='\0'){
		str1[i]=str2[j];
		i++;
		j++;
	}
	
	str1[i]='\0';
	
	cout<<endl;
	
	cout<<"Concatenation of String = "<<str1<<endl;
	
	
	return 0;
}
