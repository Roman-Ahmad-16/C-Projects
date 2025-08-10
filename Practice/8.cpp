#include<iostream>
#include<fstream>
using namespace std;

struct Student
{
	string name;
	int roll_no;
	int marks[5];
	string status;


	Student(string a , int b , int c[] , string d)
	{
		name=a;
		roll_no=b;
		status=d;
		for(int i=0; i<5; i++)
		{
			marks[i]=c[i];
		}
	}
	
		void display_info()
		{
			
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
	
	int obt_marks=0;
	int marks[5];
	int total_marks=500;
	string status;
	
	for(int i=0; i<5; i++)
	{
		cout << "Enter marks for subject " << i + 1 << ": ";
		
		cin>>marks[i];
		obt_marks+=marks[i];
	}
	
	cout<<"TOTAL MARKS :: "<<total_marks<<endl;
	cout<<"OBTAIN MARKS = "<<obt_marks<<endl;
	
	float percentage=(obt_marks/(float)total_marks)*100;
	status=(percentage>=60) ? "Pass" : "Fail";
	
	
	
	Student st("Roman" , 295 , marks ,status );
	
	
	ofstream write("Record.txt");
	
	write<<st.name<<endl;
	write<<st.roll_no<<endl;
	for(int i=0; i<5; i++){
		write<<marks[i]<<" ";
	}
	write<<endl;
	write<<percentage<<endl;
	write<<st.status<<endl;
	
	write.close();
	
	ifstream read("Record.txt");
	
	string a_name , a_status;
	int a_roll_no , a_marks[5];
	float a_percentage;
	
	read>>a_name;
	read>>a_roll_no;
	        for (int i = 0; i < 5; i++) {
            read >> a_marks[i];
        }
    read>>a_percentage;
    read>>a_status;

    read.close();
    
        Student read_student(a_name, a_roll_no, a_marks, a_status);
        read_student.display_info();
        cout << "PERCENTAGE : " << a_percentage << "%" << endl;
    
	return 0;
}
