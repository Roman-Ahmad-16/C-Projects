#include"iostream"
using namespace std;
int main(){
	
	
//	WRITE A PROGRAM THAT INPUTS 5 VALUES FROM USER IN ARRAYS AND DISPLAY THE MAXIMUM VALUES .



	int arr[5] , max;
	cout<<"ENTER FIVE VALUES TO KNOW WHICH VALUE IS MAXIMUM"<<endl;
	for( int i=0; i<5; i++){
		cout<<"ENTER VALUE = ";
		cin>>arr[i];
	}
	max=arr[0];
	
	
//	Array ka pehla number (arr[0]) ko temporarily sabse bara samjha jata hai.
//  Example: Agar array hai [10, 20, 5, 15, 25], toh initially max = 10.


	for(int i=0; i<5; i++){
		if(max<arr[i]){
			max=arr[i];
		}
		
	}
	cout<<"THE MAXIMUM VALUE IS = "<<max;
	return 0;
}
