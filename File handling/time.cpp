#include<iostream>
using namespace std;
int main(){
		
	int s;
	cout<<"ENTER TIME IN SECONDS = ";
	cin>>s;
	
	int h;
	h=s/3600;
	
	int se;
	se=s%3600;
	
	int m;
	m=se/60;
	
	int sec;
	sec=se%60;

	cout<<h<<":"<<m<<":"<<sec<<endl;
	
	return 0;
}
