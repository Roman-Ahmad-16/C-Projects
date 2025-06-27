#include<iostream>
using namespace std;
int main(){
	
	int arr[5],max,sh,flag;
	cout<<"ENTER FIVE VALUES"<<endl;
	
	for(int i=0; i<5; i++){
		cout<<"ENTER VALUE = ";
		cin>>arr[i];
	}
	
	max=arr[0];
	for(int i=0; i<5; i++){
		if(max<arr[i]){
			max=arr[i];
				flag=i;

		}
	}
	
	cout<<"MAXIMUM VALUE = "<<max<<endl;
		
	sh=arr[0];
	
	for( int i=0; i<5; i++){
		if(i==flag){
			continue;
		}
		
		if(sh<arr[i]){
			sh=arr[i];
		}
	}
	
	cout<<"SECOND HIGHEST VALUE = "<<sh<<endl;


	return 0;
}
