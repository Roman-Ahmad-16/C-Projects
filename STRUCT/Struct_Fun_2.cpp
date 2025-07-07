//Create an Employee struct with a constructor that takes name and salary.
//Add a function that checks if salary is above 50,000 and prints a message.

#include<iostream>
using namespace std;
struct Employee
{
	string name;
	int salary;
		
		Employee(string a , int b)
		{
			name=a;
			salary=b;
		}
		
	check_salary(){
		cout<<"NAME : "<<name<<endl;
		cout<<"SALARY : "<<salary<<endl;
		
		if(salary>50000){
			cout<<"SALARY IS OUT OF RANGE "<<endl;
		}else{
			cout<<"SALARY IS IN RANGE"<<endl;
		}
	}
};
int main(){
	
	Employee emp("ROMAN" , 60000);
	Employee emp1("ABUBAKAR" , 50000);
	
	cout << "\n--- Employee 1 ---\n";
	emp.check_salary();
	
    cout << "\n--- Employee 2 ---\n";
	emp1.check_salary();

}


