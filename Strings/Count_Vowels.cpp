#include<iostream>
using namespace std;
int main(){
	
	char str[20];
	int count=0;
	
	cout<<"ENTER A STRING "<<endl;
	cin.getline(str,20);
	
	int i=0;
	while(str[i]!='\0'){
		char ch=str[i];
			if(ch== 'A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || 
			   ch== 'a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'   ){
			   	count++;
			   }
			   			   	i++;

	}
			cout<<"Vowels are in String = "<<count<<endl;
	
	return 0;
}
