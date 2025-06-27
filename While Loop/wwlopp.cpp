#include<iostream>
using namespace std;
int main(){
	
//	Example 2: Print any Multiplication Table
       
       
       
       

    int num ; // Number for the multiplication table
    int i = 1;   // Counter variable
    
    cin>>num;
    while (i <= 10) { // Loop runs from 1 to 10
        cout << num << " x " << i << " = " << num * i << endl;
        ++i; // Increment the counter
        
        
    }


	return 0;
}
