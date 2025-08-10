#include<iostream>
using namespace std;

struct book
{
	string name;
	int pages;
	string author_name;	
};

void display(book b)
{
	cout<<"BOOK NAME = "<<b.name<<endl;
	cout<<"PAGES = "<<b.pages<<endl;
	cout<<"AUTHOR NAME = "<<b.author_name<<endl;
}
int main(){
	
	book b;
	
	cout<<"book name";
	cin>>b.name;
	
		cout<<"book pages";
	cin>>b.pages;
	
		cout<<"book authorname";
	cin>>b.author_name;
	
	display(b);
	return 0;
}
