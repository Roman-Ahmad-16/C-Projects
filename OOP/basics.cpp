#include <iostream>
#include <string>
using namespace std;

class Student
{

	//	DATA MEMBERS
public:
	string name;
	int age;
	float marks;

	//	MEMEBER FUNCTIONS

	void displayInfo()
	{
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Marks : " << marks << endl;
	}

	void checkResult()
	{
		if (marks >= 45)
		{
			cout << name << " has passed" << endl;
		}
		else
		{
			cout << name << " has failed" << endl;
		}
	};
};
int main()
{
	//	OBJECT CREATION

	Student s1;

	//  ASSIGNING VALUES to data members
	s1.name = "Roman";
	s1.age = 19;
	s1.marks = 85;

	//  CALLING MEMBER FUNCTIONS
	s1.displayInfo();
	s1.checkResult();

	return 0;
}
