#include <iostream>
using namespace std;

int main() {
    int SIZE = 5;

    unsigned int values[SIZE] = {2, 4, 6, 8, 10};

    unsigned int* vPtr;

    cout << "Using array subscript notation:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "values[" << i << "] = " << values[i] << endl;
    }

    vPtr = values;

    cout << "\nUsing pointer notation with vPtr:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "*(vPtr + " << i << ") = " << *(vPtr + i) << endl;
    }

    cout << "\nUsing pointer with array name (values):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "*(values + " << i << ") = " << *(values + i) << endl;
    }

    cout << "\nUsing pointer subscript notation:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "vPtr[" << i << "] = " << vPtr[i] << endl;
    }

    cout << "\nAccessing fifth element in 4 ways:\n";
    cout << "values[4]      = " << values[4] << endl;
    cout << "*(values + 4)  = " << *(values + 4) << endl;
    cout << "vPtr[4]        = " << vPtr[4] << endl;
    cout << "*(vPtr + 4)    = " << *(vPtr + 4) << endl;

    unsigned int* ptr_i = vPtr + 3;
    cout << "\nValue at vPtr + 3: " << *ptr_i << endl;

    vPtr = &values[4];   
    vPtr -= 4;           
    cout << "Value at vPtr after moving back 4: " << *vPtr << endl;

    return 0;
}

