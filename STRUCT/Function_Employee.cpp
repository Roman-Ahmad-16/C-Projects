#include<iostream>
using namespace std;

	struct employee{
		
		string name;
		int id;
		int salary;
		
	};
	
void inputdata(employee array[] , int n){
	
	for(int i=0; i<n; i++){
		
	cout << "\nEnter details for employee " << i + 1 << ":\n";
	
	cout<<"Enter name of employee :: ";
	cin>>array[i].name;
	
	cout<<"Enter id :: ";
	cin>>array[i].id;
	
	cout<<"Enter salary :: ";
	cin>>array[i].salary;
	
	}
}

void displaydata(employee array[] , int n){
	
	for(int i=0; i<n; i++){
		
	cout << "\n Details of employee " << i + 1 << ":\n";
	
	cout<<" Name of employee :: "<<array[i].name<<endl;
	cout<<" Id of employee :: "<<array[i].id<<endl;
	cout<<" Salary of employee :: "<<array[i].salary<<endl;
	
	}
}

int main(){
	
	int n;
	cout<<"ENTER NUMBER OF EMPLOYESS :: ";
	cin>>n;
	
	employee array[n];
	
	inputdata(array,n);
	displaydata(array,n);
	
	return 0;
}
