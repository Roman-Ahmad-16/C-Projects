#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to display all student records
void displayData() {
    ifstream file("Student Record.txt");
    string regNo, name;
    
    cout << "Student Records:\n";
    while (file >> regNo) {
        file.ignore(); // to skip the space or newline
        getline(file, name);
        cout << "Reg No: " << regNo << ", Name: " << name << endl;
    }
    file.close();
}

// Function to insert new student data
void insertData() {
    ofstream file("Student Record.txt", ios::app);
    string regNo, name;

    cout << "Enter Registration Number: ";
    cin >> regNo;
    cin.ignore(); // ignore newline character
    cout << "Enter Full Name: ";
    getline(cin, name);

    file << regNo << " " << name << endl;
    file.close();
    cout << "Data inserted successfully.\n";
}

// Function to update student data
void updateData() {
    ifstream inFile("Student Record.txt");
    ofstream outFile("Temp.txt");

    string regNo, name, searchRegNo, newName;
    bool found = false;

    cout << "Enter Registration Number to Update: ";
    cin >> searchRegNo;
    cin.ignore();
    cout << "Enter New Full Name: ";
    getline(cin, newName);

    while (inFile >> regNo) {
        inFile.ignore();
        getline(inFile, name);

        if (regNo == searchRegNo) {
            outFile << regNo << " " << newName << endl;
            found = true;
        } else {
            outFile << regNo << " " << name << endl;
        }
    }

    inFile.close();
    outFile.close();

    remove("Student Record.txt");
    rename("Temp.txt", "Student Record.txt");

    if (found)
        cout << "Record updated successfully.\n";
    else
        cout << "Record not found.\n";
}

// Main menu-driven function
int main() {
    int choice;
    
    cout << "Press 1 for display data\n";
    cout << "Press 2 for update data\n";
    cout << "Press 3 for insert data\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            displayData();
            break;
        case 2:
            updateData();
            break;
        case 3:
            insertData();
            break;
        default:
            cout << "Invalid choice.\n";
    }

    return 0;
}

