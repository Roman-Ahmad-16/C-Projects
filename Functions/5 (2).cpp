#include<iostream>
using namespace std;

void change(int*x){
	*x=*x+10;
	cout<<*x<<endl;
}
int main(){
	
	int a=10;
	change(&a);
	cout<<a<<endl;
	
	return 0;
}
