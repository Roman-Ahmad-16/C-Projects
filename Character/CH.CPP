#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a lowercase character: ";
    cin >> ch;

    // Check if the character is lowercase
    
    if (ch >= 'a' && ch <= 'z') {
        char upper = ch - 32; // Convert to uppercase
        cout << "The uppercase of " << ch << " is " << upper << "." << endl;
    } else {
        cout << ch << " is not a lowercase letter." << endl;
    }

    return 0;
}

