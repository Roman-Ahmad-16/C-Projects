#include<iostream>
#include<fstream>
using namespace std;
int main(){
	
	ifstream file("example.txt");
	string read;
	
	while(getline(file,read)){
		cout<<read<<endl;
	}
	file.close();
	
	return 0;
}
