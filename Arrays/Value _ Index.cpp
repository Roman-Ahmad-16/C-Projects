#include<iostream>
using namespace std;
int main(){
	
	
	int arr[6]={10,20,30,40,50,60};
	int n,loc=-2;
	
	
	cout<<"ENTER VALUE TO FIND = ";
	cin>>n;
	
	
	for(int i=0; i<6; i++){
		if(arr[i]==n){
			loc=i;
			if(loc==-2){
				cout<<"VALUE NOT FOUND IN THE ARRAY"<<endl;
			}else{
			cout<<"VALUE FOUND AT THE INDEX:"<<loc<<endl;
		}
			
		} 
	}
	
	
	
	
	
	
	
	
	return 0;
}
