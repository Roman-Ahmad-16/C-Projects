#include <iostream>
using namespace std;

	struct Student {
		
		string name;
		int age;
		int Roll_num;
		float marks;
		
	};
int main() {
	
	Student P1;
	
	cout<<"ENTER A NAME :: ";
	cin>>P1.name;
	
	cout<<"Enter a age :: ";
	cin>>P1.age;
	
	cout<<"Enter a roll num ::";
	cin>>P1.Roll_num;
	
	cout<<"Enter your marks :: ";
	cin>>P1.marks;
	
	cout<<"NAME OF STUDENT IS :: "<<P1.name<<endl;
	cout<<"AGE OF "<<P1.name<<" :: "<<P1.age<<endl;
	cout<<"ROLL-NUM OF "<<P1.name<<":: "<<P1.Roll_num<<endl;
	cout<<"MARKS OF "<<P1.name<<" :: "<<P1.marks<<endl;

    return 0;
}

