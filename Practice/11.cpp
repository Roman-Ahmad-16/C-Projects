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
	man *ptr= &m;
	
	cin>>(*ptr).p.name;
	cin>>(*ptr).p.house_no;
	
	cin>>(*ptr).area;
	cin>>(*ptr).city;
	
	cout<<(*ptr).p.name<<endl;
	cout<<(*ptr).p.house_no<<endl;
	cout<<(*ptr).area<<endl;
	cout<<(*ptr).city<<endl;
	
	delete ptr;
	
	}
