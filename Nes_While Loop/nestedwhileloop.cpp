#include <iostream>
using namespace std;

int main() {
	
//	 Inverted Number Triangle

int rows;
cout<<"ENTER NO. OF ROWS = ";
cin>>rows;



int a=rows;
while (a>=1){
	            
	            int b=1;
	            while (b<=a){
	            	cout<<b;
	            	b++;
				}
				cout<<endl;
				a--;
}
return 0;
}



//Breakdown of Loop Interaction (n = 4):
//Outer Loop (i):
//First Iteration (i = 1):
//
//Inner loop (j) stars print karta hai: * * * *
//Outer loop ek newline (endl) dalta hai.
//Second Iteration (i = 2):
//
//Inner loop firse stars print karta hai: * * * *
//Outer loop ek newline dalta hai.
//Same for i = 3 and i = 4.







