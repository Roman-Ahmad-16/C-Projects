#include<iostream>
using namespace std;
int main(){
	
	int arr[]={10,20,30,40,50};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	int *p=arr;
	int sum=0;
	
	for(int i=0; i<size; i++){
		cout<<*(p+i)<<" "<<endl;
		sum+=*(p+i);
	}
	cout<<"SUM OF VALUES = "<<sum;
	
	return 0;
}
