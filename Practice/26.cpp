#include<iostream>
using namespace std;
int main(){
	
	int r1[]={10,20,31,40,50};
	int r2[]={61,70,80,90};
	int r3[]={100,111,120};
	
	int *jagged[]={r1 , r2 , r3};
	int size[]={5 , 4 ,3};
	
	
	cout<<"ELEMENTS IN MATRIX FORM :: " <<endl;
	for(int i=0; i<3; i++){
		int *ptr=jagged[i];
		
		int even=0;
		int odd=0;
		
	for(int j=0; j<size[i]; j++){
		int num=*(ptr+j);
			if(num%2==0){
				cout<<num<<" IS EVEN"<<endl;
				even++;
			}
			else{
				cout<<num<<" IS ODD"<<endl;
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
