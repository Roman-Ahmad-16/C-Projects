#include <iostream>
using namespace std;

// Function to reverse array using pointer arithmetic
void reverseInPlace(int* arr, int n) {
    int* start = arr;
    int* end = arr + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to remove duplicates in-place
void removeDuplicates(int* arr, int& n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n;) {
            if (arr[i] == arr[j]) {
                // Shift left
                for (int k = j; k < n - 1; ++k)
                    arr[k] = arr[k + 1];
                --n;
            } else {
                ++j;
            }
        }
    }
}

// Function to square a number
void square(int& x) {
    x = x * x;
}

// Function to apply given function to all elements
void applyToAll(int* arr, int n, void (*func)(int&)) {
    for (int i = 0; i < n; ++i)
        func(arr[i]);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> *(arr + i);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i)
        cout << *(arr + i) << " ";
    cout << endl;

    reverseInPlace(arr, n);
    cout << "Reversed: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    removeDuplicates(arr, n);
    cout << "After removing duplicates: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    applyToAll(arr, n, square);
    cout << "After squaring: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}

