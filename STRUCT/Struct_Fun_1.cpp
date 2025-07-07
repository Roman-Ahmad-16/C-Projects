//Create a Student struct that stores a student’s name, roll number, and marks. 
//Use a constructor to initialize the values and a function to display them.

#include<iostream>
using namespace std;
struct 	Person
{		
	string name;
	int roll_no;
	float marks;
			
			Person(string a , int b , float c)
			{			
				name=a;
				roll_no=b;
				marks=c;
			}
			
	display(){
		cout<<"NAME : "<<name<<"\nROLL_NO : "<<roll_no<<"\nMARKS : "<<marks<<endl;
	}
};
int main(){
	
	Person P("ROMAN",295,3.91);
	P.display();
	
	return 0;
}
