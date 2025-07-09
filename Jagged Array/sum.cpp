// Create a jagged array and display the sum of elements in each row.

#include<iostream>
using namespace std;
int main(){
	
	int r1[]={10,20,30,40,50};
	int r2[]={60,70,80};
	int r3[]={90,100};
	int r4[]={110};
	
	int *jagged[]={r1,r2,r3,r4};
	int sizes[]={5,3,2,1};
	
	
	cout<<"ELEMENTS IN MATRIX FORM :: \n"<<endl;
	for(int i=0; i<4; i++){
		int *ptr=jagged[i];
			int sum=0;
			for(int j=0; j<sizes[i]; j++){
				cout<<*(ptr+j)<<" ";
					sum+=*(ptr+j);
			}
			cout<<"SUM OF ELEMENTS OF ROW "<<i+1<<" :: "<<sum<<endl;
			cout<<endl;
	}
	return 0;
}
