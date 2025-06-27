#include <iostream>
using namespace std;

int main() {
	
//	7. Multiplication Table of a Range

    int start = 2, end = 5;

    int i = start;
    while (i <= end) {
        cout << "Table of " << i << ":" << endl;
        int j = 1;
        while (j <= 10) {
            cout << i << " x " << j << " = " << i * j << endl;
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}

