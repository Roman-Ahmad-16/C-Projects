#include<iostream>
using namespace std;


void menu(){
	cout<<" 1 . ADDITION "<<endl;
	cout<<" 2 . SUBTRACTION "<<endl;
	cout<<" 3 . MULTIPLICATION "<<endl;
	cout<<" 4 . DIVISION "<<endl;

}

  int add(int a , int b){
  	return a+b;
  }
  
  int subtract(int a , int b){
  	return a-b;
  }
  
  int multiply(int a , int b){
  	return a*b;
  }
  
  int divide(int a , int b){
  	if(b==0){
  		cout<<"Enter a valid number "<<endl;
	  }
	  return a/b;
  }
  
  
  int main(){

   int choice , a , b , ans;
   
   				cout<<"	WELCOME TO OUR CALCULATOR "<<endl;
   				cout<<" ENTER TWO VALUES "<<endl;
   				cin>>a>>b;
   				
   while(true){
   	
  
   menu();
   cout<<" ENTER YOUR CHOICE "<<endl;
   cin>>choice;

   if (choice==1){
   	ans=add(a,b);
   	cout<<ans<<endl;
   }
   else if(choice==2){
   	ans=subtract(a,b);
   	cout<<ans<<endl;
   }
   else if (choice==3){
   	ans=multiply(a,b);
   	cout<<ans<<endl;
   }
   else if(choice==4){
   	ans=divide(a,b);
   	cout<<ans<<endl;
   }
   else { 
    cout<<"SELECT A VALID NUMBER "<<endl;
   }

 }

	return 0;
}


