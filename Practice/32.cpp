#include<iostream>
using namespace std;
int main()
{
	int r1[]={10,20,30,40,50};
	int r2[]={60,70,80,90};
	int r3[]={100,110,120};
	
	int *jagged[]={r1,r2,r3};
	int size[]={5,4,3};
	
	cout<<" ELEMNTS :: "<<endl;
	
	for(int i=0; i<3; i++){
		int *ptr=jagged[i];
		
		int sum=1;
		
		
			for(int j=0; j<size[i]; j++){
				cout<<*(ptr+j)<<" ";
				sum*=*(ptr+j);
			}
			cout<<endl;
			cout<<"Sum of Row = "<<sum;
			cout<<endl;
	}
	return 0;
}
