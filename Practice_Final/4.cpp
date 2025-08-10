#include <iostream>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
	
	Student s[2];

    for(int i = 0; i < 2; i++) {
    	
    	cout << "\nStudent " << i + 1 << ":\n";

		cout<<"NAME:";
		cin>>s[i].name;
		
        cout << "Roll Number: ";
        cin >> s[i].rollNo;

        cout << "Marks: ";
        cin >> s[i].marks;
    }

    cout << "\nStudent Details:\n";
    for(int i = 0; i < 2; i++) {
    	
    	cout << "\nStudent " << i + 1 << ":\n";

    	cout<<"NAME: "<<s[i].name<<endl;
        cout << "Roll No: " << s[i].rollNo << endl;
        cout << "Marks: " << s[i].marks << endl;
    }

    return 0;
}

