#include<iostream>
#include <fstream>
using namespace std;
int main(){
	
	
					DISPALY ARRAY IN VERTICAL FORM 


	int arr[5];
	for(int i=0; i<5; i++){
		cin>>arr[i];
	}
	for(int j=0; j<5; j++){
		cout<<arr[j]<<endl;
	}


      			Write a program that displays the divisors numbers

	 int arr[5];
	 for(int i=0; i<5; i++){
	 	cin>>arr[i];
	 }
	 
	 for(int i=0; i<5; i++){
	 	cout<<"\nDIVISORS OF NUMBER = "<<arr[i]<<": ";
	 	for(int j=1; j<=arr[i]; j++){
	 		if(arr[i]%j==0){
	 			cout<<j<<" ";
			 }
		 }
	 }

					Perfect Number Program


	int num;
	cin>>num;
	
	int div , sum=0;
	for (int i=1; i<num; i++){
		div=num%i;
		if(div==0){
			sum=sum+i;
		}
	}
	if(sum==num){
		cout<<"PERFECT NUM";
	}
	else{
		cout<<"not"<<endl;
	}


 								Program to Print First 100 Prime Numbers and Their Sum


	bool prime(int num){
		if(num<=1){
			return false;
		}
		for(int i=2; i*i<=num; i++){
			if(num%i==0){
				return false;
			}
		}
		return true;
	}

int main(){

	int count=0;
	int number=2;
	int sum=0;

	while(count<100){
		if(prime(number)){
			cout<<number<<endl;
			sum=sum+number;
			count++;
		}
		number++;
	}
    cout << "Sum of first 100 prime numbers is " << sum;



	 			Program Using File Handling to Show Repeated Values



		int n;
		cout<<"size of array = ";
		cin>>n;
		
		ofstream file("repeat.txt");
		int value;
		for(int i=0; i<n; i++){
			cin>>value;
			file<<value<<" ";
		}
		file.close();
		
		int arr[n];
		ifstream file1("repeat.txt");
		for(int j=0; j<n; j++){
			file1>>arr[j];
		}
		file1.close();

    	cout << "Repeated values are:\n";
		for(int i=0; i<n; i++){
			if(arr[i]!=0){
				int rep=arr[i];
				int count=0; 
				
			for(int j=0; j<n; j++){
				if(arr[j]==rep){
					count++;
					arr[j]=0;
				}
			}
			if(count>=2){
				cout<<rep<<endl;
			}
		}
	}



				2D ARRAY


		int arr[3][3];
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				cin>>arr[i][j];
			}
		}
		
		for(int a=0; a<3; a++){
			for(int b=0; b<3; b++){
				cout<<arr[a][b]<<"\t";
			}
			cout<<endl;
		}

		
		Dynamic Memory (sum)
		
		int *ptr=new int [5];
		int sum=0;
		
		cout<<"ENTER ARRAY ELEMNTS :: "<<endl;
		for(int i=0; i<5; i++){
			cin>>ptr[i];
		}
		
		for(int j=0; j<5; j++){
			sum=sum+ptr[j];
		}
		cout<<sum<<endl;
		
		delete[] ptr;

	
		
		


	return 0;
}
