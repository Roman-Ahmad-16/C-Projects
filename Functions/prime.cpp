#include<iostream>
using namespace std;

int prime(int number, int i=2){
	
	if(number<=1){
		cout<<"NUMBER IS NOT PRIME "<<endl;
		return 0;
		
	}else{
		while(i*i<=number){
			if(number%i==0){
				cout<<"NUMBER IS NOT PRIME "<<endl;
				return 0;
			}
			i++;
		}
		cout<<number<<" is a prime number. "<<endl;
	}
	
}

int main(){
	
	int i=2;
	int number;

	
	cout<<"Enter a number = ";
	cin>>number;

    prime(number,i);
    
    
	return 0;
}


