#include<iostream>
using namespace std;
int main(){
	
	const int size=3;
	
	int A[size][size],B[size][size],sum[size][size];
	
	cout<<"ENTER VALUES FOR FIRST MATRIX 3x3 :: ";
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cin>>A[i][j];
		}
	}
	
	cout<<"ENTER VALUE FOR SECOND MATRIX 3x3 :: ";
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cin>>B[i][j];
		}
	}
	
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			sum[i][j]=A[i][j]+B[i][j];
		}
	}
	
	cout<<"SUM OF MATRIX :: "<<endl;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout<<sum[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
