#include<iostream>
#include<cstring>
using namespace std;
int main(){
	
	char str1[]="hello";
	char str2[]="romanhello";


	char*found=strstr(str2,"hello");

	
	if (found) {
        cout << "Substring found at: " << found << endl;
    } else {
        cout << "Substring not found." << endl;
    }
	return 0;
}
