#include <iostream>
using namespace std;
struct student 
{
	int array[3];
};
int main(){
	
	student A[3];
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
				cout << "Enter marks for student " << i+1 << ", subject " << j+1 << ": ";
			cin>>A[i].array[j];
		}
	}
	
	for(int i=0; i<3; i++){
		cout << "Marks of student " << i+1 << ": ";
		for(int j=0; j<3; j++){
			cout<<A[i].array[j]<<" ";
		}
		cout<<endl;
	}
    return 0;
}

