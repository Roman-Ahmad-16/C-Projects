#include <iostream>
using namespace std;

int main() {
    long value1 = 200000;       // long integer
    char var2 = 'A';            // character variable
    char var1;                  // another character variable

    // Pointer to char
    char* charPtr;
    charPtr = &var2;            // pointing to var2

    // Display value pointed by charPtr
    cout << "*charPtr = " << *charPtr << endl;

    // Copy value from pointer to var1
    var1 = *charPtr;
    cout << "var1 = " << var1 << endl;
    cout << "var2 = " << var2 << endl;

    // Now using a char pointer on a long variable (not safe)
    char* intPtr;
    intPtr = (char*)&value1;    // typecast long* to char*

    // Print the first byte of value1 (due to char* only reading 1 byte)
    cout << "*intPtr = " << *intPtr << endl;

    return 0;
}

