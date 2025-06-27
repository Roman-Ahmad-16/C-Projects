#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void countCharacters(const string& filename, int& vowels, int& consonants, int& digits, int& specialChars) {
    vowels = specialChars = digits = consonants= 0;

    ifstream file(filename.c_str()); 
    char ch;
    while (file.get(ch)) {
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(ch)) {
            digits++;
        } else if (!isspace(ch)) {
            specialChars++;
        }
    }

    file.close();
}

int main() {
    string filename;
    cout << "Enter the filename to read: ";
    getline(cin, filename);

    int vowels, consonants, digits, specialChars;
    countCharacters(filename, vowels, consonants, digits, specialChars);

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits: " << digits << endl;
    cout << "Special characters: " << specialChars << endl;

    return 0;
}
