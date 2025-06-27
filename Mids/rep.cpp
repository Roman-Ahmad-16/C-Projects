#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    ofstream writeFile("data.txt");
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        writeFile << val << " ";
    }
    writeFile.close();

    int arr[n];
    ifstream readFile("data.txt");
    for (int i = 0; i < n; i++) {
        readFile >> arr[i];
    }
    readFile.close();




    cout << "Repeated values are:\n";
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            int rep = arr[i];
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (arr[j] == rep) {
                    count++;
                    arr[j] = 0; 
                }
            }

            if (count >= 2) {
                cout << rep << endl;
            }
        }
    }

    return 0;
}

