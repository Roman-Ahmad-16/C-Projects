#include<iostream>
using namespace std;

struct book
{
	string name;
	int pages;
	string author_name;		
};

void input(book array[] , int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"ENTER NAME OF EMPLOYEE = ";
		cin>>array[i].name;
		
		cout<<"Enter id :: ";
	 	cin>>array[i].pages;
	
		cout<<"Enter salary :: ";
		cin>>array[i].author_name;
	}
}

void display(book array[] , int n)
{
		for(int i=0; i<n; i++)
	{
		cout<<" NAME OF EMPLOYEE = "<<array[i].name<<endl;
	
		
		cout<<" id :: "<<array[i].pages<<endl;
	 
	
		cout<<" salary :: "<<array[i].author_name<<endl;
		
	}
}
int main(){
	
	int n;
	cout<<"number of employees = ";
	cin>>n;
	
	book array[n];
	
	input(array , n);
	display(array , n);
	
	return 0;
}
