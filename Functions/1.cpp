#include<iostream>
#include<cstring>
using namespace std;
int main(){
	
	char str1[]={'a','s','d','f','g'};
	char str2[]={'e','r','t','u','i'};
	
	strcpy(str1,str2);
	cout<<str1<<endl;
	
	return 0;
}
