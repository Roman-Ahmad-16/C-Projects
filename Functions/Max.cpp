#include <iostream>
using namespace std;

int max(int num1 , int num2){
	
	if(num1>num2){
		cout<<num1<<" IS A GREATER NUMBER"<<endl;
	}else{
		cout<<num2<<" IS THE GREATER NUMBER"<<endl;
	}
	
}

int main() {

      int  num1 , num2;
      cout<<"ENTER FIRST NUMBER = ";
      cin>>num1;
      
      cout<<"ENTER SECOND NUMBER = ";
      cin>>num2;
      
      max(num1,num2);
        
    return 0;
}

