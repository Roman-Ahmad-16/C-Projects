#include<iostream>
#include<fstream>
using namespace std;
int main(){
	
	ifstream file("example.txt");
	string read;
	
	getline(file,read);
	cout<<read;
	
	file.close();
	return 0;
}
