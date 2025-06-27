#include <iostream>
using namespace std;

int main() {
	
	
//	 Calculate the Power of a Number


   /* int base, exponent, result = 1;

    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

    int i = 1;
    while (i <= exponent) {
        result *= base; // Multiply base repeatedly
        i++;
    }

    cout << base << "^" << exponent << " = " << result << endl;*/




int base, exponent, result = 1;

    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

for(int i=1; i<=exponent; i++)
result *= base;
    cout << base << "^" << exponent << " = " << result << endl;




    return 0;
}

