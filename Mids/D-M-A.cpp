#include<iostream>
using namespace std;
int main(){
	
//	int *ptr=new int ;
//	*ptr=10;
//	cout<<*ptr<<endl;
//	delete ptr;

//	int *arr=new int[5];
//	delete[] arr;
	
	int size;
	cin>>size;
	
	int *arr= new int [size];
	for(int i=0; i<size; i++){
		arr[i]=i+1;
	}

	for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
	}
	delete[] arr;

	
	
	return 0;
} 
