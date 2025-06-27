#include<iostream>
using namespace std;
int main(){
	
//	Print any Multiplication Table in from any start to end  

	
	int num;
	int start;
	int end;
	
	cout<<"ENTER A NUMBER =";
	cin>>num;
	cout<<"ENTER A STARTING VALUE=";
	cin>>start;
	cout<<"ENTER A ENDING VALUE=";
	cin>>end;
	
	
 
	int i=start;
	while(i<=end){
		
		cout<<num<<"  X  "<<i<<"   =   "<<num*i<<endl;
		i++;
	
	}
	
	
	
	if (start > end) {
    cout << "Error: Starting value ending value se zyada nahi ho sakti.\n";
    }
  
 
    return 0;
}

	
	
	
	

