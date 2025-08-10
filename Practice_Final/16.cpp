#include<iostream>
using namespace std;

void input(int array[][2] , int rows)
{
	for(int i=0; i<rows; i++){
		for(int j=0; j<2; j++){
			cin>>array[i][j];
		}
	}
}

void output(int array[][2] , int rows)
{
	for(int i=0; i<rows; i++){
		for(int j=0; j<2; j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	
	int rows=2;
	int array[rows][2];
	
	input(array , rows);
	output(array , rows);
	
	return 0;
}
