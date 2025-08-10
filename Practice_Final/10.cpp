
//						WRITE A C++ PROGRAM THAT TAKE DATA OF 2 STUDENTS USING ARRAY FROM USER AND STORE IN FILE AND THEM DISPLAY DATA

#include <iostream>
#include<fstream>
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
    
    ofstream file("STUDENT_DATA.txt");
    for(int i=0; i<2; i++){
    	
    	file<<s[i].name<<endl;
    	file<<s[i].rollNo<<endl;
    	file<<s[i].marks<<endl;
	}
	file.close();

	cout << "\nData successfully written to file.\n";

    cout << "\nStudent Details:\n";
    
    ifstream read("STUDENT_DATA.txt");
    
    for(int i = 0; i < 2; i++) {
    	
    	cout << "\nStudent " << i + 1 << ":\n";

    	read>>s[i].name;
        read >>s[i].rollNo;
        read >>s[i].marks;
        
        cout << "Name: " << s[i].name << endl;
        cout << "Roll No: " << s[i].rollNo << endl;
        cout << "Marks: " << s[i].marks << endl;
    }
	read.close();
	
	
    return 0;
}

