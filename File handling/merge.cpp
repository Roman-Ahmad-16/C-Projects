
//												MERGE 2 FILES


#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	
	string line;
	ofstream file("Final.txt",ios::app);
	
	ifstream f1("LINES.txt");
	while(getline(f1,line)){
		file<<line<<endl;
	}
	
	ifstream f2("ROMIi.txt");
		while(getline(f2,line)){
		file<<line<<endl;
	}
}
