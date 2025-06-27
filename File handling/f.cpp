#include<iostream>
#include<fstream>
using namespace std;

createfile(){
	
	int arr[5];
	int sum=0;
	
	ofstream file("ROMIi.txt");
	
	for(int i=0; i<5; i++){
		cin>>arr[i];
		file<<arr[i]<<"\n";
		sum+=arr[i];
	}
	
	file<<"SUM = "<<sum<<endl;
	file<<"HI ROMI HOW ARE YOU";
	cout<<"SUM = "<<sum<<"\n";

	file.close();
}

readfile(){
	
	string line;
	ifstream read("ROMIi.txt");
	while(getline(read,line));
	cout<<line;

	read.close();
}

int main(){
	
	createfile();
	readfile();

	return 0;
}
