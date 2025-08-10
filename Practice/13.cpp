#include<iostream>
using namespace std;
int main()
{
	int rows=3;
	int cols=3;
	
	int **arr=new int*[rows];
	for(int i=0; i<rows; i++){
		arr[i]=new int [cols];
	}
	
	for(int a=0; a<rows; a++){
		for(int b=0; b<cols; b++){
			cin>>arr[a][b];
		}
	}
	
	for(int a=0; a<rows; a++){
		for(int b=0; b<cols; b++){
			cout<<arr[a][b]<<" ";
		}
		cout<<endl;
	}
	
	for(int c=0; c<rows; c++){
		delete[] arr[c];
	}
	
	delete[] arr;
	
	return 0;
}
