#include<iostream>
using namespace std;
int main(){
	
	int r1[]={10,20,30,40,50};
	int r2[]={60,70,80};
	int r3[]={90,100};
	int r4[]={110};
	
	int *jagged[]={r1,r2,r3,r4};
	int sizes[]={5,3,2,1};
	
	cout<<"ELEMENTS IN MATRIX FORM :: "<<endl;
	for(int i=0; i<4; i++){
		int *ptr=jagged[i];
			for(int j=0; j<sizes[i]; j++){
				cout<<*(ptr+j)<<" ";
			}
			cout<<endl;
	}
	return 0;
}
