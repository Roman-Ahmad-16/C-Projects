#include<iostream>
using namespace std;
int main()
{
	int rows =3 ;
	int cols =3;
	
	int array[rows][cols];
	
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cin>>array[i][j];
		}
	}
	
	for(int j=0; j<rows; j++){
		int sum=0; 
			for(int i=0; i<cols; i++){
				cout<<array[i][j]<<" ";
				sum+=array[i][j];
			}
			cout<<"Sum = "<<sum<<endl;
	}
	
	
	return 0;
}
