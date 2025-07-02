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
	man *ptr=&m;
	
	cout<<"ENTER NAME OF A PERSON :: ";
	cin>>(*ptr).p.name;
	
	cout<<"ENTER HOUSE_NO :: ";
	cin>>(*ptr).p.house_no;
	
	cout<<"ENTER ADDRESS OF A PERSON :: ";
	cin>>(*ptr).p.address;
	
	cout<<"ENTER STREET_NO :: ";
	cin>>(*ptr).street_no;
	
	cout<<"ENTER AREA :: ";
	cin>>(*ptr).area;

	cout<<"ENTER CITY :: ";
	cin>>(*ptr).city;
	
	
	cout<<"\n\n\n"<<endl;
	
	
	cout<<"NAME OF A PERSON :: "<<(*ptr).p.name<<endl;
	cout<<"HOUSE_NO :: "<<(*ptr).p.house_no<<endl;
	cout<<"ADDRESS :: "<<(*ptr).p.address<<endl;
	cout<<"STREET_NO :: "<<(*ptr).street_no<<endl;
	cout<<"AREA :: "<<(*ptr).area<<endl;
	cout<<"CITY :: "<<(*ptr).city<<endl;
	return 0;
}
