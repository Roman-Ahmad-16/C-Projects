#include <iostream>
using namespace std;

int main() {
    int age;

    // User se age input lena
    cout << "Apni umar dijiye: ";
    cin >> age;

    // Age check karna
    if (age >= 18) {
        cout << "Mubarak ho! Aap driving ke liye eligible hain." << endl;
    } else {
        cout << "Aap driving ke liye eligible nahi hain. Barae mehrbani " 
             << 18 - age << " saal intezar kijiye." << endl;
    }

    return 0;
}
