//	Student Record System
//
//Create a Student struct with a constructor that initializes name, roll number, and marks of 5 subjects (array).
//Use file handling to write student data to a file.
//Read data from file and display it.
//Also calculate percentage and display pass/fail status.

#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	string name;
	int roll_no;
	int marks[5];
	string status;
	
		student(string a , int b , int c[] , string d){
			name=a;
			roll_no=b;
			status=d;
			for(int i=0; i<5; i++){
				marks[i]=c[i];
			}
		}
		
	display_info(){
		cout<<"NAME :: "<<name<<endl;
		cout<<"ROLL_NO :: "<<roll_no<<endl;
		cout<<"MARKS :: ";
	    for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
		cout<<"STATUS :: "<<status<<endl;
	}
};

int main(){
	
	int marks[5];
    int obt_marks=0;
    string status;
    int total_marks=500;

    
	for(int i=0; i<5; i++){
		cout << "Enter marks for subject " << i + 1 << ": ";
		cin>>marks[i];
		obt_marks+=marks[i];
	}
	
	cout<<"TOTAL MARKS :: "<<total_marks<<endl;
	cout<<"OBTAIN MARKS = "<<obt_marks<<endl;
	
	float percentage=(obt_marks/(float)total_marks)*100;	
//	cout<<"PERCENTAGE :: "<<percentage<<"%"<<endl;
	
	status=(percentage>=45) ? "Pass" : "Fail";
//    (condition) ? value_if_true : value_if_false

	student st("ROMAN" , 295 , marks , status );

	ofstream file("Record.txt");
	file<<st.name<<endl;
	file<<st.roll_no<<endl;
        for (int i = 0; i < 5; i++) {
            file <<marks[i] << " ";
        }
    file << endl;
	file<<percentage<<endl;
	file<<st.status<<endl;

	file.close();

    ifstream fin("Record.txt");

        string a_name, a_status;
        int a_roll, a_marks[5];
        float a_percentage;

        fin >> a_name;
        fin >> a_roll;
        for (int i = 0; i < 5; i++) {
            fin >> a_marks[i];
        }
        fin >> a_percentage;
        fin >> a_status;
        fin.close();

        // Create object from file and display
        student read_student(a_name, a_roll, a_marks, a_status);
        read_student.display_info();
        cout << "PERCENTAGE : " << a_percentage << "%" << endl;
    
	return 0;
}
