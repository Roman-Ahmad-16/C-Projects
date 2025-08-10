#include<iostream>
using namespace std;
int main()
{
	int a , b , c;
	
	cout<<"ENTER THE SIZE OF ARRAY :: "	<<endl;
	cin>>a;
	
	cout<<"ENTER THE SIZE OF 2nd ARRAY :: "	<<endl;
	cin>>b;
	
	cout<<"ENTER THE SIZE OF 3rd ARRAY :: "	<<endl;
	cin>>c;	
	
	int *p , *q , *r;
	
	p=&a;
	q=&b;
	r=&c;
	
	int r1[a];
	int r2[b];
	int r3[c];
	
	int *jagged[]={r1 , r2 , r3};
	int *size[]={p , q , r};
	
	for(int i=0; i<3; i++){
		int *ptr=jagged[i];
		
		for(int j=0; j<*size[i]; j++){
			cin>>*(ptr+j);
		}
	}
	
	for(int i=0; i<3; i++){
		int *ptr=jagged[i];
		
		for(int j=0; j<*size[i]; j++){
			cout<<*(ptr+j)<<" ";
		}
		cout<<endl;
	}
	
	
	
	
	return 0;
}
