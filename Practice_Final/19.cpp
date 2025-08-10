#include<iostream>
using namespace std;
int main()
{
	int max_value=0;
	int rows =3 ;
	int cols =3;
	
	int array[rows][cols];
	
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cin>>array[i][j];
		}
	}
	
	max_value=array[0][0];
	for(int j=0; j<rows; j++){
			for(int i=0; i<cols; i++){
				cout<<array[i][j]<<" ";
				if(array[i][j]>=max_value)
				{
					max_value=array[i][j];
				}
			}
		cout<<endl;	
	}
		cout<<"Max Value = "<<max_value<<endl;

	
	return 0;
}
