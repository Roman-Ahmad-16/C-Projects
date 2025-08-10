#include<iostream>
#include<fstream>
using namespace std;

struct Student
{
	string name;
	int roll_no;
	int marks;
};
int main()
{
	int roll;
	cout<<"ENTER ROLL N0 TO FIND = ";
	cin>>roll;
	
	Student st;
	
	ifstream read("Read.txt");
	while(read>>st.name>>st.roll_no>>st.marks)
	{
		if(roll==st.roll_no)
		{
			cout<<"NAME OF STUDENT :: "<<st.name<<endl;
			cout<<"ROLL_NO OF STUDENT :: "<<st.roll_no<<endl;
			cout<<"MARKS OF STUDENT :: "<<st.marks<<endl;
			break;
		}
		else
		{
			cout<<"NO STUDENT FOUND ";
			break;
		}		
	}
	read.close();
	
	return 0;
}
