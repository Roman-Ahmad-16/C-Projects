#include<iostream>
using namespace std;

int shape(int num , char ch){
	
	for(int i=1; i<=num; i++){
		cout<<endl;
		for(int j=1; j<=num; j++){
			cout<<ch;
		}
	}
}


int main(){
	
int num;
cout<<"ENTER A NUMBER = ";
cin>>num;

char ch;
cout<<"ENTER A CHARACTER = ";
cin>>ch;

shape(num,ch);
     
     
    
	return 0;
}


