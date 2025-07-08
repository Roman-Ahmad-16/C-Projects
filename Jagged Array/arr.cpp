#include<iostream>
using namespace std;
int main(){
	
	int a, b, c;
	int *p,*q,*r;
	
	cout<<"ENTER THE SIZE OF ARRAY :: "	<<endl;
	cin>>a;
	
	cout<<"ENTER THE SIZE OF 2nd ARRAY :: "	<<endl;
	cin>>b;
	
	cout<<"ENTER THE SIZE OF 3rd ARRAY :: "	<<endl;
	cin>>c;	
	
	p=&a;
	q=&b;
	r=&c;
	
	int r1[a];
	int r2[b];
	int r3[c];
	
	int* jagged[]={r1,r2,r3};
	int* sizes[]={p,q,r};
	
	cout<<"ENTER VALUES :: "<<endl;
	for(int i=0; i<3; i++){
		int *ptr=jagged[i];
			for(int j=0; j<*sizes[i]; j++){
				cin>>*(ptr+j);
			}
	}
	
	cout<<" VALUES in matrix form  :: "<<endl;
	for(int i=0; i<3; i++){
		int *ptr=jagged[i];
			for(int j=0; j<*sizes[i]; j++){
				cout<<*(ptr+j)<<" ";
			}
			cout<<endl;
	}
	return 0;
}
