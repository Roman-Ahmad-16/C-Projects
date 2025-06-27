#include"iostream"
using namespace std;
int main(){
	
//	PRINT SUM OF SQUARES OF SERIES 
	
	double a , b=1 , sum=0.0 ;	
	cout<<"ENTER A NUMBER = ";
	cin>>a;
	
	while (b<=a){
		         

				sum+=1.0/(b*b);
		    b++;    
	}
	
	cout<<sum;
	

	return 0;
}
