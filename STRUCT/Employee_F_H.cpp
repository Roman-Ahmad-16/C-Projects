//	Write a program to read data from a file that contains information of Employee struct. Display the data

#include<iostream>
#include<fstream>
using namespace std;

	struct Employee{
		string name;
		int id;
		int salary;
	};
int main(){
	
	Employee emp;
	ifstream read("Employee.txt");
	
	    cout << "EMPLOYEE DATA FROM FILE:\n\n";

	while(read>>emp.name >> emp.id >> emp.salary){
		cout<<"NAME OF EMPLOYEE :: "<<emp.name<<endl;
		cout<<"ID OF EMPLOYEE :: "<<emp.id<<endl;
		cout<<"SALARY OF EMPLOYEE :: "<<emp.salary<<endl;
		cout << "--------------------------\n";

	}
	read.close();
	return 0;
}

