#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
	
	ofstream file("2D.txt");
	file<<"ALI"<<endl;
	file<<"AHMAD"<<endl;
	file<<"EHSAN"<<endl;
	file<<"ROMAN"<<endl;
	file<<"ALI AHAMD"<<endl;
	file<<"ALI MALIK"<<endl;
	file.close();
	
	ifstream file1("2D.txt");
	
	const int MAX_NAMES=100;
	const int MAX_LENGTH=50;
	
	char name[MAX_NAMES][MAX_LENGTH];
	int count=0;
	
	while(file1.getline(name[count],MAX_LENGTH)){
		cout<<"NAME = "<<name[count]<<endl;
		count++;
	}
	file1.close();
	
	ofstream file3("reverse.txt");
	
	for(int i=count-1; i>=0; i--){
		file3<<name[i]<<endl;
	}
	file3.close();
	
	return 0;
}
