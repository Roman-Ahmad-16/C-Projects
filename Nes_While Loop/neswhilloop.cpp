#include <iostream>
using namespace std;

int main() {
	
//	 Square Pattern of Stars. 
	
	
    int n;
    cout << "Enter the size of the square: ";
    cin >> n;

    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            cout << "* ";
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}
