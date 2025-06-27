#include<iostream>
#include<cstring>
using namespace std;
int main(){
	
	char str1[]="adjsmfkoe";
	char str2[]="adjsmfkone";


	int result=strcmp(str1,str2);
	
	if(result==0){
		cout<<"Strings are equal"<<endl;
	}	
	else{
		cout<<"not"<<endl;
	}
	return 0;
}
