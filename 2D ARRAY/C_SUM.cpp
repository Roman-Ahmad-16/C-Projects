#include<iostream>
using namespace std;

int main(){
    int rows = 3;
    int cols = 3;
    int arr[rows][cols];
    
	cout<<"ENTER VALUES FOR ARRAY 3X3 :: ";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> arr[i][j];
        }
    }

    for(int j = 0; j < cols; j++){  
        int sum = 0;
        for(int i = 0; i < rows; i++){
			cout<<arr[i][j]<<" ";
            sum += arr[i][j];
        }
        cout << "Sum of Column " << j + 1 << " = " << sum << endl;
    }

    return 0;
}
