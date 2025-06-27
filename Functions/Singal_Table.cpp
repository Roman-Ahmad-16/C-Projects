#include <iostream>
using namespace std;

int table(int number){
	
	for(int i=1; i<=10; i++){
		cout<<number<<" X "<<i<<" = "<<number*i<<endl;
	}
}

int main() {

        int number;
        cout<<"ENTER A NUMBER TO DISPLAY A TABLE = "<<endl;
        cin>>number;

table(number);

    return 0;
}

