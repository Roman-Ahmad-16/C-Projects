#include<iostream>
using namespace std; 
int main(){
	
	int rows=2;
	int cols=2;
	
	int **arr=new int*[rows];
	for(int i=0; i<rows; i++){
		arr[i]=new int[cols];
	}
	
	for(int a=0; a<rows; a++){
		for(int b=0; b<cols; b++){
			cin>>arr[a][b];
		}
	}
	
	for(int a=0; a<rows; a++){
		for(int b=0; b<cols; b++){
			cout<<arr[a][b]<<"\t";
		}
		cout<<endl;
	}
	
	for(int e=0; e<rows; e++){
		delete[] arr[e];
	}
	
	delete[] arr;
	
	return 0;
}
