#include<iostream>
#include<cstring>
using namespace std;
int main(){
	
	char str1[]="hello";
	cout<<"LENGTH = "<<strlen(str1)<<endl;
	

	char a[]="roman";
	char b[10];
	cout<<"COPY = "<<strcpy(b,a)<<endl;
	
	
	char c[]="roman";
	char d[]="ahmad";
	cout<<"Concatenated = "<<strcat(c,d)<<endl;
	
	
	char str2[]="roman ahmad";
	char str3[]="roman ehsan";
	if(strcmp(str2,str3)==0){
		cout<<"Comparison Equal"<<endl;
	}else{
		cout<<"NOT COMPARE"<<endl;
	}
	
	
return 0;
}
