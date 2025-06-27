#include"iostream"
using namespace std;
int main(){
	
//	Program 7: Prime number check

int no;
cout<<"ENTER A NUMBER = ";
cin>>no;
	
	
	if(no<=1){
	     cout<<no<<" is not prime "<<endl;
	    
}else{

for(int i=2; i*i<=no; i++){
	  	
	  	              if(no%i==0){
	  	  	          cout<<no<<" is not prime "<<endl;
	  	  	          return 0;

			          }

}
		cout<<no<<" is a prime number "<<endl;
}
	
	
	
	return 0;
}
