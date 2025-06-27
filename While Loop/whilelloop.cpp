#include<iostream>
using namespace std;
int main(){
	
	int a=1,num,even=0,odd=0,zero=0;
	cout<<" ENTER A NUMBER = ";
	
	

	while (a<=5)
	           {
		
		cin>>num;
		        if(num==0)
				{
					zero++;
				}
				else if(num%2!=0)
		        {
				
		        	odd++;
				}
				else 
				{
					even++;
				}
			a++;	
	}
	
	cout<<"THERE ARE "<<even<<" EVEN NUMBERS"<<endl;
	cout<<"THERE ARE "<<odd<<" ODD NUMBERS"<<endl;
	cout<<"THERE ARE "<<zero<<" ZERO NUMBERS"<<endl;

	
return 0;	
	
}
