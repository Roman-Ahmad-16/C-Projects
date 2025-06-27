#include<iostream>
#include<fstream>
using namespace std;
int main(){
	
		string line , line1;
		
		ofstream writefile("roman.txt");
		writefile<<"ROMAN FILE HANDLING PROJECT "<<endl;
		
		getline(cin,line);
		writefile<<line;
		
		writefile.close();
		
		
		ifstream readfile("roman.txt");
		while(getline(readfile,line1)){
			cout<<line1<<endl;
		}
		
		readfile.close();
		
	return 0;
}
