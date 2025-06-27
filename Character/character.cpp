
//Program 1: Check if a Character is a Vowel or Consonant

#include<iostream>
using namespace std;
int main(){
	
	char ch;
	cout<<"ENTER A CHARACTER TO CHECK"<<endl;
	cin>>ch;
	
	if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
	
	   ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' ){
	   	
	   cout<<"CHARACTER IS VOWEL"<<endl;
	   }else{
	   	cout<<ch<<" is consonant ";
	   }
	
	
	
	return 0;
}
