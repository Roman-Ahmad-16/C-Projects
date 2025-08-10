#include<iostream>
#include<fstream>
using namespace std;

struct employee
{
	string name;
	int id;
	int salary;	
};

int main(){
	
	employee emp;
	
	ifstream read("Employee.txt");
	while(read>>emp.name>>emp.id>>emp.salary){
		cout<<"NAME OF EMPLOYEE :: "<<emp.name<<endl;
		cout<<"ID OF EMPLOYEE :: "<<emp.id<<endl;
		cout<<"SALARY OF EMPLOYEE :: "<<emp.salary<<endl;
	}
	
	read.close();
	
	return 0;
}
