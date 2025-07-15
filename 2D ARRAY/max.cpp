//#include<iostream>
//using namespace std;
//int main(){
//	
//	int max_value;
//	int rows=3;
//	int cols=3;
//	
//	int arr[rows][cols];
//	
//	cout<<"ENTER VALUES FOR ARRAY 3X3 :: ";
//	for(int i=0; i<rows; i++){
//		for(int j=0; j<cols; j++){
//			cin>>arr[i][j];
//		}
//	}
//	
//	
//	max_value =  arr[0][0];
//
//	for(int i=0; i<rows; i++){
//		for(int j=0; j<cols; j++){
//			cout<<arr[i][j]<<" ";
//		if(arr[i][j]>max_value){
//			max_value=arr[i][j];
//			}
//		}
//		cout<<endl;
//	}
//	cout<<"MAX VALUE = "<<max_value;
//	
//	return 0;
//}
#include <iostream>
using namespace std;

int main() {
    const int size = 3;
    int A[size][size], B[size][size], sum[size][size];

    cout << "Enter elements of first 3x3 matrix:\n";
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of second 3x3 matrix:\n";
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cin >> B[i][j];
        }
    }

    // Matrix Addition
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            sum[i][j] = A[i][j] * B[i][j];
        }
    }

    // Output Result
    cout << "\nSum of the matrices:\n";
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

