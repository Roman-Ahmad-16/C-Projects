#include<iostream>
using namespace std;

	struct Book{
		
		string name;
		int price;
		string author_name;
		int pages;
		
	};
	
	void displaybooks(Book b){
		cout<<"NAME OF BOOK IS :: "<<b.name<<endl;
		cout<<"PRICE OF BOOK IS :: "<<b.price<<endl;
		cout<<"AUTHOR OF BOOK IS :: "<<b.author_name<<endl;
		cout<<"PAGES OF BOOK ARE :: "<<b.pages;
	}
int main(){
	
	Book b;
	
	cout<<"ENTER NAME OF BOOK :: ";
	cin>>b.name;
	
	cout<<"ENTER PRICE OF BOOK :: ";
	cin>>b.price;
	
	cout<<"ENTER AUTHOR NAME OF BOOK :: ";
	cin>>b.author_name;
	
	cout<<"HOW MANY PAGES ARE IN BOOK :: ";
	cin>>b.pages;
	
	displaybooks(b);
	
	return 0;
}
