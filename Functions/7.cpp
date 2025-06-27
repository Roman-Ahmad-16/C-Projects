#include<iostream>
#include<cstring>
using namespace std;
int main(){
	
	char str1[]="adjsmfkoe";


	char*result=strchr(str1,'k');
	
if (result == 0) {
        cout << "not found" << endl;
    } 
    else {
        cout << "found at position " << (result - str1) << endl;
    }

	return 0;
}
