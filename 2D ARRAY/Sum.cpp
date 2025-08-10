#include <iostream>
using namespace std;

int main() {
    const int size = 3;
    int A[size][size], B[size][size], sum[size][size];

    cout << "Enter elements of first 3x3 matrix:\n";
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of second 3x3 matrix:\n";
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cin >> B[i][j];
        }
    }

    // Matrix Addition
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    // Output Result
    cout << "\nSum of the matrices:\n";
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

