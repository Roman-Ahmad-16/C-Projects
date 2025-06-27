#include<iostream>
using namespace std;
int main(){
	
	
//	Example 1: Sum of First 10 Natural Numbers


    int number = 1; // Start from 1
    int sum = 0;    // Variable to store the sum

    while (number <= 10) { // Loop runs from 1 to 10
        sum +=number;    // Add current number to sum
        number++;         // Increment the number
    }

    cout << "The sum of the first 10 natural numbers is: " << sum << endl;



	
	return 0;
}
