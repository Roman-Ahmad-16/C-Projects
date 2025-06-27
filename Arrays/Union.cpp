#include<iostream>
using namespace std;
int main(){
	
	int arr1[]={10,2,30,50};
	int arr2[]={20,30,10,34};
	
	int n1=sizeof(arr1)/sizeof(arr1[0]);
	int n2=sizeof(arr2)/sizeof(arr2[0]);
	
	for(int i=0; i<n1; i++){
		cout<<arr1[i];
	}
	
	for(int i=0; i<n2; i++){
	
	int found=0;
	
	for(int j=0; j<n1; j++){
		if(arr2[i]==arr1[j]){
			found=1;
		}
	}
	
	if(!found){
		cout<<arr2[i];
	}
	}
	return 0;
}
