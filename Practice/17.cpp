#include<iostream>
using namespace std;

void input(int array[2][2] )
{
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			cin>>array[i][j];
		}
	}
}

void output(int array[2][2])
{
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	
	int array[2][2];
	
	input(array );
	output(array );
	
	return 0;
}
