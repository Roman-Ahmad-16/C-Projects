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
	

	
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(array[i][j]==array[0][0]){
				cout<<"VALUE = "<<array[i][j]<<" MATCH AT THE INDEX = "<<i<<"x"<<j<<endl;
			}
		}
	}
	return 0;
}
