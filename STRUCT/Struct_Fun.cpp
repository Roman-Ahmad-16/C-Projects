#include<iostream>
using namespace std;
struct 	Person
{		
	string name;
	float height;
	int age;
			
			Person(string a , float b , int c)
			{			
				name=a;
				height=b;
				age=c;
			}
			
	display(){
		cout<<"NAME : "<<name<<"\nHEIGHT : "<<height<<"\nAGE : "<<age<<endl;
	}
};
int main(){
	
	Person P("ROMAN",5.4,19);
	P.display();
	
	return 0;
}
