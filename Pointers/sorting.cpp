#include<iostream>
using namespace std;
int main(){
	
	int arr[10],temp;
	cout<<"ENTER THE ARRAY VALUES"<<endl;
	for(int a=0; a<10; a++){
		cin>>arr[a];
	}
	
	cout<<"VALUES BEFORE SORTING "<<endl;
	for(int b=0; b<10; b++){
		cout<<" "<<arr[b]<<endl;
	}
	
	for(int c=0; c<10; c++)
	{
		for(int d=c+1; d<10; d++)
		{
			if(arr[c]<arr[d])
			{
				temp=arr[c];
				arr[c]=arr[d];
				arr[d]=temp;
			}
		}
	}
	
	cout<<"VALUES AFTER SORTING"<<endl;
	for(int e=0; e<10; e++){
		cout<<" "<<arr[e]<<endl;
	}
	
	
	return 0;
}
