#include<iostream>
using namespace std;
int main(){
	
	int max_value;
	int rows=3;
	int cols=3;
	
	int arr[rows][cols];
	
	cout<<"ENTER VALUES FOR ARRAY 3X3 :: ";
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cin>>arr[i][j];
		}
	}
	
	
	max_value =  arr[0][0];

	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout<<arr[i][j]<<" ";
		if(arr[i][j]>max_value){
			max_value=arr[i][j];
			}
		}
		cout<<endl;
	}
	cout<<"MAX VALUE = "<<max_value;
	
	return 0;
}

