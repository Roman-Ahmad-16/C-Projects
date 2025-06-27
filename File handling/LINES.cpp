
//																LINES COUNT


#include<iostream>
#include<fstream>
using namespace std;
int main(){
		
	ofstream file("LINES.txt");
	file<<"hello \nbscs \nsection f \nbatch 2024";
	file.close();
	
	string line;
	int num=0;
	
	ifstream read("LINES.txt");
	while(getline(read,line)){
		
		cout<<line<<endl;
		
		num++;
	}
	cout<<"NO. OF LINES = "<<num;
	read.close();
	return 0;
}

