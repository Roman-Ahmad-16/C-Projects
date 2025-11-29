#include <iostream>
using namespace std;
class Student
{
private:
	int roll_no;
	float marks;

public:
	void set_data(int a, float b)
	{
		roll_no = a;
		marks = b;
	}

	void display()
	{

		cout << "ROLL_NO :: " << roll_no << endl;
		cout << "MARKS :: " << marks << endl;
	}
};
int main()
{

	Student st;

	st.set_data(101, 87.5);
	st.display();

	return 0;
}
