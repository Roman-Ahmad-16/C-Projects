#include<iostream>
using namespace std;

int powerr(int num , int power , int ans=1){
	for(int i=1; i<=power; i++){
		ans=ans*num;
	}
	cout<<"POWER OF A NUMBER = "<<ans<<endl;
}

int main(){
	
     int num;
     int ans=1;
     
     cout<<"ENTER A NUMBER = "<<endl;
     cin>>num;
     
     int power;
     cout<<"ENTER A POWER = "<<endl;
     cin>>power;
    
    powerr(num,power,ans);
    
    
	return 0;
}
