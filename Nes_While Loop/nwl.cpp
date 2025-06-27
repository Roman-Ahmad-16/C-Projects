#include <iostream>
using namespace std;

int main(){
		
	//3. Number Pyramid   
		
	int number;
	cout<<"enter a number = ";
	cin>>number;
	
	int a=1;
	while(a<=number){
		        
		        int b=1;
		        while (b<=a){ 
		        cout<<b;
		        b++;
				}
				cout<<endl;
			a++;	
	}
	
	return 0;
}
