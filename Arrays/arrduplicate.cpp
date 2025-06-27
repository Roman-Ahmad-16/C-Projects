#include <iostream>
using namespace std;

int main() {
    int arr1[5], arr2[5];
    
    cout << "Enter 5 numbers for first array: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr1[i];
    }

    cout << "Enter 5 numbers for second array: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr2[i];
    }

    cout << "Duplicate numbers in both arrays: ";
    bool foundDuplicate = false;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr1[i] == arr2[j]) { 
                cout << arr1[i] << " ";
                foundDuplicate = true;
                break; 
            }
        }
    }

    if (!foundDuplicate) {
        cout << "None";
    }

    return 0;
}

