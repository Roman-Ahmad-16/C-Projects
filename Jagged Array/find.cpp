//c++ program which compare the values of 1st row of 2d array with remainig values and 
//print the values with their index value and the size of array minimum 3x3.

#include<iostream>
using namespace std;
int main(){
	
	const int rows=3;
	const int cols=3;
	
	int array[rows][cols];
	
	cout<<"ENTER VALUES :: "<<endl;
	
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cin>>array[i][j];
		}
	}
	
	cout<<"VALUES OF 2D ARRAY :: "<<endl;
	
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int compare=array[0][0];
	
	cout << "\nComparing first value (" << compare << ") with 2nd and 3rd row...\n";

	for(int i=1; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(array[i][j]==compare){
				cout<<"VALUE :: "<<array[i][j]<<" MATCH AT THE INDEX (" << i << "," << j << ")\n"; 
			}
		}
	}
	return 0;
}
