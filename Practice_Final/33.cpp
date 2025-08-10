#include<iostream>
using namespace std;

class Student {
	
	private:
		string name;
		float marks;
		int roll_no;
		
	public:
		void data(string a , float b , int c)
		{
			name=a;
			marks=b;
			roll_no=c;
		}
	void display()
	{
		cout<<"NAME = "<<name<<endl;
		cout<<"Marks = "<<marks<<endl;
		cout<<"Roll NO = "<<roll_no<<endl;
	}
};
int main(){
	
	Student st;
	
	st.data("AbuBakar " , 45.9 , 299);
	st.display();
	
	return 0;
}
