#include <iostream>
#include <string>
using namespace std;

class Person
{

public:
	string name;
	int age;

	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
		cout << "Hi , I am parent constructor" << endl;
	}

};

class Student : public Person
{
public:
	int rollno;

	Student(string name, int age, int rollno) : Person(name, age)
	{
		this->rollno = rollno;
		cout << "Hi , I am child constructor" << endl;
	}

	void getInfo()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Roll No: " << rollno << endl;
	}
};

int main()
{
	Student s1("Roman", 19, 295);
	s1.getInfo();

	return 0;
}