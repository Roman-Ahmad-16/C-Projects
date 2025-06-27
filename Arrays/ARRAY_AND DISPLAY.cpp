#include"iostream"
using namespace std;
int main(){
	
//	WRITE A PROGRAM THAT INPUTS 5 INTEGERS FROM USER STORE IN 
//  ARRAY AND DISPLAY ALL VALUES IN ARRAY USING LOOPS.

	cout<<"ENTER FIVE INTEGERS"<<endl;

int a[5];
for( int i=0; i<5; i++){
	cout<<"ENTER INTEGERS = ";
    cin>>a[i];
}



cout<<" THE VALUES IN ARRAY ARE "<<endl;
for( int i=0; i<5; i++){
cout<<a[i]<<endl;
}


return 0;
}
