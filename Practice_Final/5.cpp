#include<iostream>
using namespace std;

struct person
{
		string name;
		int house_no;
		string address;	
};

struct man
{		
		int street_no;
		string area;
		string city;
		person p;
};

int main(){
	
	man m;
	
	cout<<"ENTER NAME "; 
	cin>>m.p.name;
	
	cout<<"house no ";
	cin>>m.p.house_no;
	
	cout<<"area ";
	cin>>m.area;
	
	cout<<"city ";
	cin>>m.city;
	
	cout<<"NAME OF A PERSON :: "<<m.p.name<<endl;
	cout<<"HOUSE_NO :: "<<m.p.house_no<<endl;
	cout<<"AREA :: "<<m.area<<endl;
	cout<<"CITY :: "<<m.city<<endl;
	return 0;
}
