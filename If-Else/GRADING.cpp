#include<iostream>
using namespace std;
int main(){
	
	int marks;
	cout<<"ENTER YOUR MARKS TO CHECK YOUR GRADE "<<endl;
	cin>>marks;
	
	if (marks>=70 & marks<80){
		cout<<"YOUR GRADE IS c"<<endl;
	}
	else if (marks>=80 & marks<90){
		cout<<"YOUR GRADE IS b"<<endl;
	}
	else if (marks>=90 & marks<100){
		cout<<" YOUR GRADE IS A"<<endl;
	}
	else if (marks>=0 & marks<70){
		cout<<"YOUR GRADE IS F"<<endl;
	}
	else{
		cout<<"you are fail";
	} 
	
		
	return 0;
}

