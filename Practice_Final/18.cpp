#include<iostream>
using namespace std;

struct array
{
	int array[3];	
};

int main()
{
	
	array arr[3];
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin>>arr[i].array[j];
		}
	}
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<arr[i].array[j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
