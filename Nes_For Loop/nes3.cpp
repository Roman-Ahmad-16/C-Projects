#include<iostream>
using namespace std;
int main(){
	
//	int rows,a=1;
//	cout<<"ENTER NUMBERS OF ROWS = ";
//	cin>>rows; 
//	
//	while(a<=rows){
//		int b=1;
//		       while(b<=a){
//		       	cout<<"*";
//		       	b++;
//			   }
//			   cout<<endl;
//			   a++;
//	}


int sum;
for( int i=1; i<=5; i++){
	cout<<"1";
	sum=1;
	
	for(int j=2; j<=i; j++){
		cout<<"+"<<j;
		sum=sum+j;
	}
	cout<<" = "<<sum<<endl;
}

	return 0;
}
