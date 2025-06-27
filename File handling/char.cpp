
//																			COUNT CHARACTERS


#include<iostream>
#include<fstream>
using namespace std;
int main(){

		
	ofstream file("LINES.txt");
	file<<"hello \nbscs \nsection f \nbatch 2024";
	file.close();
	
	string line;
	int count=0;
	
	ifstream read("LINES.txt");
	while(getline(read,line)){
		
		cout<<line<<endl;
		
		count+=line.length();			
		
	}
	cout<<" character = "<<count;
	read.close();
	return 0;
}
