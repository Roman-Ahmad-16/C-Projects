#include<iostream>
using namespace std;

int square(int num){
	
	return num*num;
	
}

int cube(int a , int num){
	
	return a*num;
	
}


int main(){
	
    int num;
    cout<<"ENTER A NUMBER = "<<endl;
    cin>>num;
    
    int a;
    a=square(num);
    cout<<"SQUARE OF A NUMBER = "<<a<<endl;
    
    int b;
    b=cube(a,num);
    cout<<"CUBE OF A NUMBER = "<<b<<endl;

	return 0;
}


