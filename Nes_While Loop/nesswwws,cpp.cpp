#include <iostream>
using namespace std;

int main(){
	
//	Right-Angled Triangle Pattern

int rows;
cout<<"ENTER YOUR ROWS = ";
cin>>rows;

int i=1;
while (i<=rows){
	     
	     int j=1;
	     while(j<=i){
	     	cout<<"*";
	     	j++;
		 }
		 cout<<endl;
		 i++;
		 
}

    return 0;
}

	
//Inner loop start hota hai: j = 1.
//Condition: j <= i ? 1 <= 2 ? True ? Star print.
//Next: j = 2, j <= i ? 2 <= 2 ? True ? Dusra star print.
//Inner loop terminate ho jata hai (j = 3 aur j > i ho gaya)
	

