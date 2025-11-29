#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	string name;
	double *cgpaPtr;

	Student(string name, double cgpa)
	{
		this->name = name;
		cgpaPtr = new double;
		*cgpaPtr = cgpa;
	}

	//	Destructor

	~Student()
	{
		cout << "Hi , I delete every thing " << endl;
		delete cgpaPtr;
	}

	void getInfo()
	{
		cout << "Name : " << name << endl;
		cout << "CGPA : " << *cgpaPtr << endl;
	}
};

int main()
{
	Student s1("Roman", 3.91);
	s1.getInfo();

	return 0;
}
