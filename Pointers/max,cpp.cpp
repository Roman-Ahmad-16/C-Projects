#include <iostream>
using namespace std;

int maxvalue(int* ptr, int size) {
    int* max = ptr;
    for (int i = 1; i < size; i++) {
        if (*(ptr + i) > *max) {
            max = ptr + i;
        }
    }
    return *max;
}

int minivalue(int* ptr, int size) {
    int* min = ptr;
    for (int i = 1; i < size; i++) {
        if (*(ptr + i) < *min) {
            min = ptr + i;
        }
    }
    return *min;
}

int main() {
    int size;
    cout << "ENTER THE SIZE OF ARRAY = ";
    cin >> size;

    // NOTE: This uses a Variable-Length Array (allowed in GCC)
    int arr[size];

    int* ptr = arr;
    for (int i = 0; i < size; i++) {
        cout << "VALUE OF ARRAY AT THE INDEX = " << i << " ";
        cin >> *(ptr + i);
    }

    cout << "Maximum : " << maxvalue(arr, size) << endl;
    cout << "Minimum : " << minivalue(arr, size) << endl;

    return 0;
}

