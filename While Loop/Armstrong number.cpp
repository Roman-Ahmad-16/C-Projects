#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num, original, remainder, sum = 0, digits = 0;

    cout << "Enter a number: ";
    cin >> num;

    original = num;

    // Count the number of digits
    while (num != 0) {
        digits++;
        num /= 10;
    }

    num = original; // Reset num to original value

    // Calculate the sum of digits raised to the power of digits
    while (num != 0) {
        remainder = num % 10;
        sum += pow(remainder, digits);
        num /= 10;
    }

    // Check if the number is Armstrong
    if (sum == original) {
        cout << original << " is an Armstrong number." << endl;
    } else {
        cout << original << " is not an Armstrong number." << endl;
    }

    return 0;
}

