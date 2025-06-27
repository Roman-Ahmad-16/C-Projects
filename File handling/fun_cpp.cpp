#include<iostream>
#include<fstream>
using namespace std;

createfile(){
	
	ofstream file("ROMI.txt");
	file<<"HI ROMI HOW ARE YOU";
	file.close();
}

readfile(){
	
	string line;
	ifstream read("ROMI.txt");
	while(getline(read,line));
	cout<<line;
	read.close();
}

int main(){
	
	createfile();
	readfile();
	
	return 0;
}
