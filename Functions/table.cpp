#include<iostream>
using namespace std;


int table(int number,int start,int end){
	
	  if(end<start){
      	cout<<"STARTING AND ENDING POINT IS NOT VALID"<<endl;
	  }
	  
	  
	for(int i=start; i<=end; i++ ){
		
	 cout<<number<<" X "<<i<<" = "<<number*i<<endl;
	}
	
}


int main(){
	
	int number;
	cout<<"ENTER NUMBER OF TABLE YOU WANT TO DISPLAY = ";
	cin>>number;
	
	
	int start;
	cout<<"ENTER STARTING NUMBER = ";
	cin>>start;
	
	
	int end;
	cout<<"ENTER ENDING NUMBER = ";
	cin>>end;
	
	table(number,start, end);
	
	return 0;
}
