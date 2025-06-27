#include<iostream>
using namespace std;


void countEvenOdd(int n, int &evenCount, int &oddCount){
	
	
	evenCount=0;
	oddCount=0;
	
	
	for(int i=1; i<=n; i++){
		if(i%2==0){
			evenCount++;

		}
		else {
			oddCount++;

		}
	}
	cout << "Total Even Numbers: " << evenCount << endl;
    cout << "Total Odd Numbers: " << oddCount << endl;
	
}
    
  int main(){
  	
  	 int n;
     int evenCount=0,oddCount=0;     


     cout<<"ENTER A NUMBER = "<<endl;
     cin>>n;

     countEvenOdd(n , evenCount , oddCount);

     
	return 0;
}


