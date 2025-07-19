#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
int main(){
	
	string user;
	cout<<"ENTER A STRING :: ";
	getline(cin,user);
	
	ofstream file("palindrome.txt");
	file<<user;
	file.close();
	
	ifstream file1("palindrome.txt");
	
	char arr[1000];
	int i=0;
	char ch;
	
	while(file1.get(ch)){
		arr[i]=ch;
		i++;
	}
	
	arr[i]='\0';
	file1.close();
	
	int count=strlen(arr);
	
	bool palindrome=true;
	for(int j=0; j<count/2; j++){
		if(arr[j]!=arr[count-j-1]){
			palindrome=false;
			break;
		}
	}
	
	if(palindrome){
		cout<<"THE STRING IS PALINDROME";
	}
	else{
		cout<<"THE STRING IS NOT PALINDROME";
	}
	return 0;
}
