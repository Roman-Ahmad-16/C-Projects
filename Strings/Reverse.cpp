
#include <iostream>
using namespace std;

int main() {
    char str[100];
    int i;

    cout << "Enter Your Name: ";
    cin.get(str, 100);

    for (i = 0; i < 100; i++) {
        if (str[i] == '\0') {
            break; 
			 
        }
    }

    cout << "Reversed Name: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << str[j];
    }
    
    cout << endl;
    return 0;
}

