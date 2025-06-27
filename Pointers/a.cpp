#include<iostream>
using namespace std;

	int main(){
	
	int arr[3]={1,56,43};
	
	cout<<arr<<endl;
	cout<<*arr<<endl;
	cout<<*(arr+1)<<endl;

	for(int i=0; i<3; i++){
		cout<<*(arr+i)<<" "<<endl;
	}

	int a=10 , b=60 , c=90;
	int *ptr[3];
	
	ptr[0]=&a;
	ptr[1]=&b;
	ptr[2]=&c;
	
	for(int i=0; i<3; i++){
		cout<<*ptr[i]<<endl;
	}
	
	
	int arr[3]={10,20,30};
	int(*p)[3]=&arr;
	
	cout<<(*p)[0]<<endl;
	cout<<(*p)[1]<<endl;
	
		
	int arr[3]={10,20,30};
	
	int *p=arr;
	int product=1;
	
	for(int i=0; i<3; i++){
		product*=*(p+i);
	}
	cout<<product<<endl;
	
	

	void fun(int *ptr,int size){
		int pro=1;
		for(int i=0; i<3; i++){
			pro*=*(ptr+i);
		}
		cout<<pro<<endl;
	}
	
	int main(){
		
	int arr[]={10,20,30};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	fun(arr,size);
	
	return 0;
}
