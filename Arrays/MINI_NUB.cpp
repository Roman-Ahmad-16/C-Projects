#include"iostream"
using namespace std;
int main(){
	
//	WRITE A PROGRAM THAT INPUTS 5 NUMBERS FROM USER IN ARRAY AND DISPLAYS THE MINIMUM NUMBER.

	int arr[5],mini;
	cout<<"ENTER VALUES TO CHECK WHICH IS MINIMUM"<<endl;
	for(int i=0;i<=4; i++){
		cout<<"ENTER VALUE = ";
		cin>>arr[i];
	}
	
	mini=arr[0];
	for(int i=0;i<=4; i++){
		if(mini>arr[i]){
			mini=arr[i];
		}
}
		cout<<"THE MINIMUM VALUE IS = "<<mini<<endl;

	
	return 0;
}
