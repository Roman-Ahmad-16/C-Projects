
//																	MERGE 2 FILES IN TO 3 FILE


#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	
	ofstream outfile1("1.txt");
	outfile1<<"hello\n bscs";
	outfile1.close();
	
	ofstream outfile2("2.txt");
	outfile2<<"hello\n bscs 2 \n section f";
	outfile2.close();
	
	string line;
	ofstream outfile3("3.txt" , ios::app);
	
	ifstream infile1("1.txt");
	while(getline(infile1,line)){
		
		outfile3<<line<<endl;
	}
	infile1.close();
	
	
	ifstream infile2("2.txt");
	while(getline(infile2,line)){
		
		outfile3<<line<<endl;
	}
	
	
	infile2.close();
	outfile3.close();
	return 0;
}
