
//															MERGE first FILE INTO second FILE


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream file1("11.txt");

    file1 << " roman" << endl;
    file1.close();

    ofstream file2("22.txt", ios::app);

    file2 << " hello" << endl;

    ifstream file3("11.txt");

    string line;
    while (getline(file3, line)) {
        file2 << line << endl;
    }

    file2.close();
    file3.close();

    cout << "Files successfully merged!" << endl;

    return 0;
}

