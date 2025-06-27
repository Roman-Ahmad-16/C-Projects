#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
    ifstream file("example.txt"); 
    string read;

    file >> read;
    cout << "File ka pehla word: " << read << endl;

    file.close(); 
    return 0;
}

