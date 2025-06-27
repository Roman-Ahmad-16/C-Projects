#include<iostream>
#include<cstring>
using namespace std;
int main(){



	char str2[]="Civic";
	char str3[]="Civics";
	
	if(strcmp(str2,rev(str3))==0){
		cout<<"Comparison Equal"<<endl;
	}else{
		cout<<"NOT COMPARE"<<endl;
	}
	
	
return 0;
}
