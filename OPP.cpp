#include <iostream>
#include <string>
using namespace std;


//Encapsulation is the process of binding data and functions together into a single unit 
//(class) and restricting direct access to some of the object’s components for data protection.

//Class ke andar data (variables) aur functions (methods) ko ek sath rakhna,
//aur data ko private bana kar use sirf functions ke zariye access karna.


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
