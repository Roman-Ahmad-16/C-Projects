//	Write a program to search a student by roll number from a file.

#include<iostream>
#include<fstream>
using namespace std;

	struct Student{
		string name;
		int roll_no;
		int marks;
	};
int main(){
	
	Student st;
	
	int roll_no;
	cout<<"Enter roll_no for serach :: ";
	cin>>roll_no;
	
	cout << "--------------------------\n";

	ifstream read("Student.txt");
	while(read>>st.name >> st.roll_no >> st.marks){
		if(roll_no==st.roll_no){
			cout<<"NAME OF STUDENT :: "<<st.name<<endl;
			cout<<"ROLL_NO OF STUDENT :: "<<st.roll_no<<endl;
			cout<<"MARKS OF STUDENT :: "<<st.marks<<endl;
			break;
		}
	}
	read.close();
	return 0;
}

