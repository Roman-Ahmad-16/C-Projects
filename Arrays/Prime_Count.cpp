#include<iostream>
using namespace std;
int main(){
	
	//	WRITE A PROGRAM THAT INPUTS 10 NUMBERS FROM USER IN ARRAY.THE PROGRAM SHOULD FIND 
   //	OUT HOW OF THEM ARE PRIME NUMBERS.


    int arr[10], p, count = 0, c;

    cout << "ENTER 10 NUMBERS TO FIND HOW MANY OF THEM ARE PRIME NUMBERS" << endl;
  
    for (int i = 0; i < 10; i++) {
        cout << "ENTER VALUE = ";
        cin >> arr[i];
    }

    // Check for prime numbers
    for (int i = 0; i < 10; i++) {
        if (arr[i] < 2) {
            continue; // Skip numbers less than 2
        }

        p = 1; // Assume the number is prime
        for (c = 2; c <= arr[i] / 2; c++) {
            if (arr[i] % c == 0) {
                p = 0; // Not a prime number
                break;
            }
        }

        if (p == 1) {
            count++; // Increment count if prime
        }
    }

    cout << "TOTAL PRIME NUMBERS ARE = " << count << endl;
	
   return 0;	
}
