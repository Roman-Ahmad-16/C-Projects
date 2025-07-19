#include <iostream>
using namespace std;

void zero(long Big_Integers[], int size);
int sum(int oneTooSmall[], int size);

int main() {
    long Big_Integers[5] = {10, 20, 30, 40, 50};
    int oneTooSmall[5] = {1, 2, 3, 4, 5};

    zero(Big_Integers, 5);

    cout << "Big_Integers after zero function: ";
    for (int i = 0; i < 5; i++) {
        cout << Big_Integers[i] << " ";
    }
    cout << endl;

    int result = sum(oneTooSmall, 5);
    cout << "Sum after adding 1 to each element: " << result << endl;

    return 0;
}

void zero(long Big_Integers[], int size) {
    for (int i = 0; i < size; i++) {
        Big_Integers[i] = 0;
    }
}

int sum(int oneTooSmall[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        oneTooSmall[i] += 1;
        sum += oneTooSmall[i];
    }
    return sum;
}

