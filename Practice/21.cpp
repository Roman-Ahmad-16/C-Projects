#include<iostream>
using namespace std;
int main(){
	
	const int size=3;
	
	int A[size][size],B[size][size],product[size][size]={0};
	
	cout<<"ENTER VALUES FOR FIRST MATRIX 3x3 :: ";
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cin>>A[i][j];
		}
	}
	
	cout<<endl;
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	cout<<"ENTER VALUE FOR SECOND MATRIX 3x3 :: ";
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cin>>B[i][j];
		}
	}
	
	cout<<endl;
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			for(int k=0; k<size; k++)
			product[i][j]+=A[i][k]*B[k][j];
		}
	}
	
	cout<<"PRODUCT OF MATRIX :: "<<endl;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout<<product[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
