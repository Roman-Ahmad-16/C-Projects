#include <iostream>
using namespace std;

int main() {
	
    int arr[5], duplicateCount = 0;
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[i] == arr[j]) {
                duplicateCount++;
                break;
            }
        }
    }

    cout << "Total duplicate numbers: " << duplicateCount;
    return 0;
}

