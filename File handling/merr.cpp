#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	
	ofstream file1("A.txt");
	file1<<"HELLO ";
	file1.close();
	
	ofstream file2("B.txt");
	file2<<" ROMAN";
	file2.close();
	
	ifstream file3("B.txt");
	ofstream file11("A.txt" , ios::app);
	
	string str;
	while(getline(file3,str)){
		
		file11<<str<<endl;
		
	}
	file11.close();
	file3.close();
	
	cout<<"DATA DONE";
	return 0;
}
