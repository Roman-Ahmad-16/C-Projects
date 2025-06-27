#include<iostream>
using namespace std;


int even(int number){
	if(number%2==0){
		cout<<number<<" IS A EVEN NUMBER "<<endl;
	}else{
		cout<<number<<" IS ODD NUMBER "<<endl;
	}
}

int main(){
	
	int i=2;
	int number;
	
	
    cout<<"ENTER A NUMBER = ";
    cin>>number;
    
    even(number);
    
	return 0;
}


