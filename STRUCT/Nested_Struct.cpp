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
	
	cout<<"ENTER NAME OF A PERSON :: ";
	cin>>m.p.name;
	
	cout<<"ENTER HOUSE_NO :: ";
	cin>>m.p.house_no;
	
	cout<<"ENTER ADDRESS OF A PERSON :: ";
	cin>>m.p.address;
	
	cout<<"ENTER STREET_NO :: ";
	cin>>m.street_no;
	
	cout<<"ENTER AREA :: ";
	cin>>m.area;

	cout<<"ENTER CITY :: ";
	cin>>m.city;
	
	
	cout<<"\n\n\n"<<endl;
	
	
	cout<<"NAME OF A PERSON :: "<<m.p.name<<endl;
	cout<<"HOUSE_NO :: "<<m.p.house_no<<endl;
	cout<<"ADDRESS :: "<<m.p.address<<endl;
	cout<<"STREET_NO :: "<<m.street_no<<endl;
	cout<<"AREA :: "<<m.area<<endl;
	cout<<"CITY :: "<<m.city<<endl;
	return 0;
}
