#include"iostream"
using namespace std;
int main(){
	
	// Print any table 
	
	int a;
	cout<<"Enter a table number = ";
	cin>>a;
	
	int b;
	cout<<"Enter starting value = ";
	cin>>b;
	
	int c;
	cout<<"Enter ending value = ";
	cin>>c;
	
	for (int i=1; b<=c; b++){
		cout<<a<<" X "<<b<<" = "<<a*b<<endl;
	}
	
	
	
	
	return 0;
}
