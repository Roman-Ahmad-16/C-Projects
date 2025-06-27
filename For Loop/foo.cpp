#include"iostream"
using namespace std;
int main(){
	
	
//	CALCULATE THE POWER OF ANY NUMBER 

int no;
cout<<"ENTER A NUMBER = ";
cin>>no;

int p;	
cout<<"enter a power = ";
cin>>p;	

int b=1	
for(int i=1; i<=p; i++){
	b*=no;
}	
	cout<<b;
	
	
	
	
	
	return 0;
}
