#include<iostream>
#include<fstream>
using namespace std;
int main(){
	
	string read;
	ifstream file("my file.txt");
	file>>read;
	
	cout<<read<<endl;
	file.close();
	return 0;
}
