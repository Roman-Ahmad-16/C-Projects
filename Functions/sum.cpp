
// CALCULATE THE AVERAGE OF THREE NUMBERS INPUT FROM USER USING TWO FUNCTIONS 


#include<iostream>
using namespace std;

int sum(int ,int , int ){
	return a+b+c;
}

float aveg(int ){
	return ans/3;
}

int main(){
	
	int a,b,c;
	cout<<"ENTER 3 VALUES  = ";
	cin>>a>>b>>c;
	
	int ans;
	ans=sum(a,b,c);
	cout<<"Sum of these numbers are = "<<ans<<endl;
	
	float avg;
	avg=aveg(ans);
	cout<<"AVERAGE OF THESE NUMBERS  = "<<avg<<endl;

	return 0;
}
