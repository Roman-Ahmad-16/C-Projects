#include<iostream>
#include<cstring>
using namespace std;
int main(){
	
	char str1[]={'q','w','e','t','y','u'};
	char str2[]={'Q','W','E','R','T','Y'};

	strcpy(str2,str1);
	
	cout<<str2<<endl;
	
	int len=strlen(str2);
	cout<<"Length of string = "<<len<<endl;
	
	return 0;
}
