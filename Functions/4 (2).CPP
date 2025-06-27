#include <iostream>
using namespace std;

void value(int x){
	x=x+25;
	cout<<x<<endl;
}
int main(){
	
	int a=90;
	value(a);
	cout<<a<<endl;
	
	return 0;
}
