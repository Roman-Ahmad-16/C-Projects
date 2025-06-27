#include<iostream>
using namespace std;
int main(){
	
//	int arr[3][4]={
//		{10,20,30},
//		{40,50,60},
//		{70,80,90}
//		
//	};
//	
//	for(int i=0; i<3; i++){
//		for(int j=0; j<3; j++){
//			cout<<arr[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	
	
	int rows , cols ;
	cin>>rows;
	cin>>cols;
	
	int **arr=new int *[rows];
	for(int i=0; i<rows; i++){
		arr[i]=new int [cols];
	}
	
	for(int i=0; i<rows; i++){
		for (int j=0; j<cols; j++)
		arr[i][j]=i+j
		;
	}
	
	for(int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
	
	
	
	return 0;
}
