#include <iostream>
using namespace std;

int display(int num){
	
	cout<<"Presessor Of A Number = "<<num-1<<endl;
	cout<<"Successor Of A Number = "<<num+1<<endl;
}


int main() {

 int num;
 cout<<"ENTER A NUMBER = "<<endl;
 cin>>num;
 
 display(num);
 
 
    return 0;
}

