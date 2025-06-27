#include <iostream>

using namespace std;

int main() {
    char mainStr[100], subStr[100];
    

    cout << "Enter the main string: ";
    cin.getline(mainStr, 100);

    cout << "Enter the substring to search: ";
    cin.getline(subStr, 100);

    // Simple method to find substring
    
    
    for (int i = 0; mainStr[i] != '\0'; i++) {
        int j = 0;
        while ( subStr[j] != '\0' && mainStr[i + j] == subStr[j]) {
            j++;
        }

        if (subStr[j] == '\0') {  // If we reached the end of subStr, it's found
            cout << "Substring found!" << endl;
            return 0;  // Exit the program
        }
    }

    cout << "Substring not found!" << endl;
    return 0;
}

