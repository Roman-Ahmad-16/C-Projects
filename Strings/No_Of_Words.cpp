#include<iostream>
using namespace std;
int main(){
	
	char ch[100];
	int count=1;
	
	cout<<"ENTER A STRING "<<endl;
	cin.getline(ch,100);
	
	for( int i=0; i<=100; i++){
		if(ch[i]=='\0'){
			break;
	}	
		if(ch[i]==' '){
		count++;
		}
	}
	
	cout<<"NO OF WORDS ARE IN STRING = "<<count<<endl;
		
	return 0;
}
