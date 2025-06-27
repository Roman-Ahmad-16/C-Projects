#include<iostream>
using namespace std;


//  CALL BY REFRENCE PARAMETER
  
    
void swap(int &x , int &y){
	int t;
	t=x;
	x=y;
	y=t;
}

int main(){
	
int a ,b;
cout<<"ENTER A VALUE = ";
cin>>a;

cout<<"Enter amother value = ";
cin>>b; 

cout<<"	VALUES BEFORE SWAPPING  "<<endl;
     cout<<" a = "<<a<<endl;
     cout<<" b = "<<b<<endl;
    
    
cout<<"	VALUES AFTER SWAPPING "<<endl;
      swap(a,b);
      
      cout<<" a = "<<a<<endl;
      cout<<" b = "<<b<<endl;
               
	return 0;
}


