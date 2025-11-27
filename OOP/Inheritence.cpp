#include<iostream>
#include<string>
using namespace std;

class Person{
	
	public:
		string name;
		int age;
		
	Person()
	{
		cout<<"Hi , I am parent contructor"<<endl;
	}
};

class Student : public Person{
	public: 
		int rollno;
		
		Student()
	{
		cout<<"Hi , I am child contructor"<<endl;
	}
		
	void getInfo()
	{
		cout<<"Name"<<name<<endl;
		cout<<"Age"<<age<<endl;
		cout<<"Roll No"<<rollno<<endl;
	}
};
int main()
{
	Student s1("Roman" , 19 , 295);
	s1.getInfo();
	
	return 0;
}
