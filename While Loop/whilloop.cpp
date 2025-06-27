#include <iostream>
using namespace std;

int main() {
    int number, sum = 0;

    cout << "Enter a positive integer: ";
    cin >> number;



    while (number > 0) {
        sum += number % 10; // Add the last digit to the sum
        number /= 10;      // Remove the last digit
        
        
        
                if (number <= 0) {
        cout << "Please enter a positive number." << endl;
        return 1; // Exit the program
    }
    }

    cout << "The sum of the digits is: " << sum << endl;
    
    
    
    
        // Check if the number is positive



    return 0;
}

