#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    ifstream file("example.txt");
    if(file.is_open()){
    	
    	string read;
    	file>>read;
    	cout<<read;
	}
	else{
		cout<<"file not found";
	}
    
    return 0;
}

