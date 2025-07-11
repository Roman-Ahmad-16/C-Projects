#include<iostream>
using namespace std;

void input_array(int array[][2] , int rows){
	
	for(int i=0; i<rows; i++){
		for(int j=0; j<2; j++){
			cin>>array[i][j];
		}
	}
	
}

void output_array(int array[][2] , int rows){
	
	for(int i=0; i<rows; i++){
		for(int j=0; j<2; j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	
}

int main(){
	
	int rows=2;
	int array[rows][2];
	
	input_array(array,rows);
	output_array(array,rows);
	
	return 0;
}


//			2ND PROGRAM




#include<iostream>
using namespace std;

void input_array(int array[2][2]){
	
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			cin>>array[i][j];
		}
	}
	
}

void output_array(int array[2][2] ){
	
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	
}

int main(){
	
	int array[2][2];
	
	input_array(array);
	output_array(array);
	
	return 0;
}

