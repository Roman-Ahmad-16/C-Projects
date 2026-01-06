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

	//	COPY CONSTRUCTOR

	Student(Student &obj)
	{
		this->name = obj.name;

		//		Deep Copy
		cgpaPtr = new double;
		*cgpaPtr = *obj.cgpaPtr;
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
	Student s2(s1);

	s1.getInfo();

	s2.name = "Ahmad";
	*(s2.cgpaPtr) = 4;

	s2.getInfo();

	return 0;
}
