#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("example.txt"); 
    if (file.is_open()) {
        file << "Hello, File Handling in C++! \n welcome \n wellcome roman"; 
        file.close(); 
        cout << "Data likh dia gaya hai!" << endl;
    } else {
        cout << "File nahi khuli!" << endl;
    }
    return 0;
}

