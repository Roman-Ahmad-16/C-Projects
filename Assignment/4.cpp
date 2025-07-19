#include <iostream>
using namespace std;

int main() {
    int SIZE = 5;

    // Declare and initialize array
    unsigned int values[SIZE] = {2, 4, 6, 8, 10};

    // Declare pointer
    unsigned int* vPtr;

    // 1. Using array subscript notation
    cout << "Using array subscript notation:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "values[" << i << "] = " << values[i] << endl;
    }

    // Assign base address of array to pointer
    vPtr = values;

    // 2. Using pointer notation with vPtr
    cout << "\nUsing pointer notation with vPtr:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "*(vPtr + " << i << ") = " << *(vPtr + i) << endl;
    }

    // 3. Using pointer notation with array name (values)
    cout << "\nUsing pointer with array name (values):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "*(values + " << i << ") = " << *(values + i) << endl;
    }

    // 4. Using pointer subscript notation
    cout << "\nUsing pointer subscript notation:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "vPtr[" << i << "] = " << vPtr[i] << endl;
    }

    // 5. Accessing 5th element in 4 different ways
    cout << "\nAccessing fifth element in 4 ways:\n";
    cout << "values[4]      = " << values[4] << endl;
    cout << "*(values + 4)  = " << *(values + 4) << endl;
    cout << "vPtr[4]        = " << vPtr[4] << endl;
    cout << "*(vPtr + 4)    = " << *(vPtr + 4) << endl;

    // 6. Accessing element using temporary pointer
    unsigned int* ptr_i = vPtr + 3;
    cout << "\nValue at vPtr + 3: " << *ptr_i << endl;

    // 7. Move pointer to last element, then go back 4
    vPtr = &values[4];   // points to last element (index 4)
    vPtr -= 4;           // move back 4 elements (now index 0)
    cout << "Value at vPtr after moving back 4: " << *vPtr << endl;

    return 0;
}

