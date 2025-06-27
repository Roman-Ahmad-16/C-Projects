#include"iostream"
using namespace std;
int main(){
	
	int num,i=2;
	cout<<"ENTER A NUMBER = ";
	cin>>num;
	
	if(num<=1){
		       cout<<num<<" is not prime number ";
	}else{
		  while(i*i<=num){
		  	              if(num%i==0){
		  	              	           cout<<num<<" is not prime number "<<endl;
		  	              	           return 0;
							}
							i++;
		  }
		  cout<<num<<" is prime number "<<endl;
	}
	
	
	return 0;
}
