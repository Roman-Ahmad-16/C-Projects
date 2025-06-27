

//Program 2: Check if a Character is Uppercase or Lowercase


#include<iostream>
using namespace std;
int main(){
	
	
	char ch;
	cout<<"ENTER A CHARACTER = ";
	cin>>ch;
	
	if(ch>='A' && ch<='Z'){
		cout<<"CHARACTER IS UPPER CASE"<<endl;
		
		
		
	}else if(ch>='a' && ch<='z'){
		cout<<"CHARACTER IS LOWER CASE"<<endl;
		
		
		
	}else{
		cout<<"ENTER A CORRECT CHARACTER ";
	}
	
	

	
	return 0;
}
