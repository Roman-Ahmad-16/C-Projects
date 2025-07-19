#include <iostream>
using namespace std;

int main() {
    long value1 = 200000;       
    char var2 = 'A';            
    char var1;                  

    char* charPtr;
    charPtr = &var2;            

    cout << "*charPtr = " << *charPtr << endl;

    var1 = *charPtr;
    cout << "var1 = " << var1 << endl;
    cout << "var2 = " << var2 << endl;

    char* intPtr;
    intPtr = (char*)&value1;    

    cout << "*intPtr = " << *intPtr << endl;

    return 0;
}

