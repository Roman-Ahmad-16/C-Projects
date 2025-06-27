#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int countWords(const char* line) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != ' ' && line[i] != '\n') {
            if (!inWord) {
                count++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    return count;
}

int main() {
    ifstream file("t6.txt");
    char line[256];
    int lineNumber = 1;

    while (file.getline(line, 256)) {
        cout << "Line " << lineNumber << ": " << line << endl;
        int wordCount = countWords(line);
        cout << "Total words in line " << lineNumber << ": " << wordCount << "\n\n";
        lineNumber++;
    }

    file.close();
    return 0;
}

