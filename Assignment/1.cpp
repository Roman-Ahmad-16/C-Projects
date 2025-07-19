#include<iostream>
#include<fstream>
using namespace std;
int main(){
	
	ofstream file("r.txt");
	file<<"HELLO\nROMAN\nAHMAD";
	file.close();
	
	ifstream file1("r.txt");
	
	char data[1000];
	char ch;
	int i=0;
	
	while(file1.get(ch) && i<999){
		data[i]=ch;
		i++;
	}
	
	data[i]='\0';
	cout<<"CONTENT = "<<data<<endl;
	file1.close();
	
	int vowels=0;
	
	for(int j=0; data[j]!='\0'; j++){
		char c=data[j];
		
		if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
		|| c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
			
			vowels++;
		}	
	}
	cout<<"VOWELS = "<<vowels<<endl;
	
	
	ofstream outfile("r.txt" , ios::app);
	outfile<<"VOWELS = "<<vowels<<endl;	
	outfile.close();
	
	
	return 0;
	
}
