#include<iostream>
#include<string>
using namespace std;

class Teacher
{
	public:
		string name;
		string dep;
		int age;
		int salary;
		
//	Parameterized Constructor
		
	Teacher(string name , string dep , int age , int salary)
	{
		this->name=name;
		this->dep=dep;
		this->age=age;
		this->salary=salary;
	}
	
//	If(Jab bhi tum class ka object banate ho ? constructor khud hi run ho jata hai.
//	Tumhe use manually call nahi karna padta.)
	
//	Copy Constructor

	Teacher(Teacher &obj)
	{
		cout<<"Hello i am copy constructor"<<endl;
		this->name=obj.name;
		this->dep=obj.dep;
		this->age=obj.age;
		this->salary=obj.salary;
	}

	void display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Dep: "<<dep<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"Salary: "<<salary<<endl;
	}
};
int main()
{
	Teacher t1("Roman", "BSCS" , 19 , 100000);
	t1.display();

// 	Default Copy Constructor
//	Teacher t2(t1);
//	t2.display();
	
	
	Teacher t2(t1);
	t2.display();
	
	return 0;
}
