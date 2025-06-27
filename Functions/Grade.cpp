#include<iostream>
using namespace std;

char grade(int marks){
	
	if(marks>=80){
		return 'A';
	}
	else if(marks>=60){
		return 'B';
	}
	else if (marks>=40){
		return 'C';
	}
	else{
		cout<<"YOUR ARE FAIL"<<endl;
	}
}
  
  
  int main(){
   
   
   int marks;
   cout<<"ENTER MARKS = ";
   cin>>marks;
      
      char g=grade(marks);
      cout<<"YOUR GRADE IS = "<<g<<endl;
      
      
	return 0;
}


