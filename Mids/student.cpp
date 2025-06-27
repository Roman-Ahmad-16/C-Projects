#include <iostream>
#include <fstream>
#include <cstring> // for strcpy, strcmp
using namespace std;

int main() {
    int n;

    // 1. Prompt for number of students
    cout << "Enter number of students: ";
    cin >> n;

    // 2. Dynamic memory allocation
    char** names = new char*[n];
    for (int i = 0; i < n; ++i)
        names[i] = new char[51]; // max length 50 + null terminator

    int* rollNumbers = new int[n];
    float* marks = new float[n];

    // 3. Input for each student
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter data for student " << (i + 1) << ":\n";
        cout << "Name: ";
        cin.ignore(); // flush newline before getline
        cin.getline(names[i], 51);
        cout << "Roll Number: ";
        cin >> rollNumbers[i];
        cout << "Marks: ";
        cin >> marks[i];
    }

    // 4. Sort in descending order by marks (using selection sort)
    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (marks[j] > marks[maxIdx])
                maxIdx = j;
        }

        // Swap marks
        swap(marks[i], marks[maxIdx]);

        // Swap roll numbers
        swap(rollNumbers[i], rollNumbers[maxIdx]);

        // Swap names
        char temp[51];
        strcpy(temp, names[i]);
        strcpy(names[i], names[maxIdx]);
        strcpy(names[maxIdx], temp);
    }

    // 5. Write to file "students.txt"
    ofstream outFile("students.txt");
    outFile << "Name\t\tRoll No\t\tMarks\n";
    outFile << "----------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        outFile << names[i] << "\t\t" << rollNumbers[i] << "\t\t" << marks[i] << "\n";
    }
    outFile.close();
    cout << "\nData written to 'students.txt' successfully.\n";

    // 6. Deallocate memory
    for (int i = 0; i < n; ++i)
        delete[] names[i];
    delete[] names;
    delete[] rollNumbers;
    delete[] marks;

    return 0;
}

