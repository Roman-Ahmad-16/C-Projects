#include <iostream>
#include <string>
using namespace std;

class Teacher 
{
	private:
			double salary;
	public:
			string name;
			string dep;
			string subject;
		
//	setter	
	void setSalary(double s)
	{
		salary=s;
	}
	
//	getter
	double getSalary()
	{
		return salary;
	}
	
};

int main()
{
	Teacher t1;
	
	t1.name = "Roman Ahmad";
	t1.subject = "Computer Science";
	t1.dep = "BSCS";
	t1.setSalary(25000);
	
	cout<<t1.name<<endl;
	cout<<t1.getSalary()<<endl;
	
	return 0;
}
