// Count how many even and odd numbers are in each row of the jagged array.

#include<iostream>
using namespace std;
int main(){
	
	int r1[]={10,20,30,43,50};
	int r2[]={69,70,80};
	int r3[]={93,100};
	int r4[]={110};
	
	int *jagged[]={r1,r2,r3,r4};
	int sizes[]={5,3,2,1};
	
	
	cout<<"ELEMENTS IN MATRIX FORM :: \n"<<endl;
	for(int i=0; i<4; i++){
		int *ptr=jagged[i];
		
			int even=0;
			int odd=0;
			
		for(int j=0; j<sizes[i]; j++){
			int num=*(ptr+j);
				if(num%2==0){
					cout<<num<<" IS EVEN "<<endl;
						even++;
				}else{
					cout<<num<<" IS ODD "<<endl;
						odd++;
				}
		}		
			
			cout<<endl;
			cout<<"EVEN NUMBERS ARE IN ROW "<<i+1<<" :: "<<even<<endl;
			cout<<"ODD NUMBERS ARE IN ROW "<<i+1<<" :: "<<odd<<endl;
			cout<<endl;
		}
	
	return 0;
}
