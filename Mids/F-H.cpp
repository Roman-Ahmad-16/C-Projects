#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	
//												LINES COUNT
//
//	ofstream file("lines_count.txt");
//	file<<"roman \n ahmad \n ehsan \n romi";
//	file.close();
//	
//	string line;
//	int num=0;
//	ifstream read("lines_count.txt");
//	while(getline(read,line)){
//		cout<<line<<endl;
//		num++;
//	}
//	cout<<"NUM OF LINES = "<<num<<endl;
//	read.close();
//	
//	
//												LINE PRINT THROUGH LOOP 
//
//	string line,line1;
//	cout<<"ENTER A STRING :: ";
//	
//	ofstream file("line.txt");
//	getline(cin,line);
//	file<<line;
//	file.close();
//	
//	ifstream read("line.txt");
//	while(getline(read,line1)){
//		cout<<line1<<endl;
//	}
//	read.close();
//	
//	
//	
//
//												MERGE first FILE INTO second FILE
//
//
//
//	ofstream file("first.txt");
//	file<<"roman ahmad";
//	file.close();
//
//	ofstream file2("SECOND.txt" , ios::app);
//	file2<<"riyan ahmad";
//	
//	ifstream file3("first.txt");
//	string line;
//	while(getline(file3,line)){
//		file2<<line;
//	}
//	file2.close();
//	file3.close();
//
//
//
//
//													MERGE 2 FILES IN TO 3 FILE
//
//
//	string line ;
//	
//	ofstream outfile("first.txt");
//	outfile<<"roman";
//	outfile.close();
//	
//	ofstream outfile2("second.txt");
//	outfile2<<"ahmad";
//	outfile2.close();
//	
//	ofstream outfile3("result.txt" , ios::app);
//	
//	ifstream infile("first.txt");
//	while(getline(infile,line)){
//		outfile3<<line;
//	}
//	infile.close();
//	
//	ifstream infile2("second.txt");
//	while(getline(infile2,line)){
//		outfile3<<line;
//	}
//	infile2.close();
//	outfile3.close();
//	
//	cout<<"FILES ARE SUCCESSFULLY MERGED";
//
//
//
//
//															MERGE second FILE INTO first FILE
//
//
//
//	ofstream file("first.txt");
//	file<<"roman";
//	file.close();
//	
//	ofstream file2("second.txt");
//	file2<<"ahmad";
//	file2.close();
//
//	ifstream file3("second.txt");
//	ofstream file4("first.txt" , ios::app);
//	
//	string line;
//	while(getline(file3,line)){
//		file4<<line;
//	}
//	file4.close();
//	file3.close();
//	cout<<"DATA DONE";
//
//
//												COUNT CHARACTERS
//
//
//
//	ofstream file("first.txt");
//	file<<"roman ahamd";
//	file.close();
//
//	string line ;
//	int count=0;
//	
//	ifstream file2("first.txt");
//	while(getline(file2,line)){
//		count+=line.length();
//	}
//	cout<<"CHARACTERS IN THE LINE = "<<count;
//
//
//
//
//                                               THROUGH FUNCTION
//
//createfile(){
//	ofstream file("roman.txt");
//	file<<"roman\nahamd";
//	file.close();
//}
//
//readfile(){
//	string line;
//	
//	ifstream file1("roman.txt");
//	while(getline(file1,line)){
//		cout<<line;
//	}
//}
//
//int main(){
//
//
//createfile();
//readfile();
//
//
//                                       THROUGH FUNCTION (sum)
//
//
//createfile(){
//	
//	ofstream file("romi.txt");
//	cout<<"ENTER VALUES FOR ARRAY :: ";
//	
//	int arr[5];
//	int sum=0;
//	for(int i=0; i<5; i++){
//		cin>>arr[i];
//		file<<arr[i]<<" "<<endl;
//		sum+=arr[i];
//	}
//	file<<"the sum of array = "<<sum<<endl;
//	file.close();
//}
//
//readfile(){
//	
//	string line;
//	ifstream file1("romi.txt");
//	while(getline(file1,line)){
//		cout<<line<<" ";
//	}
//	file1.close();
//}
//
//int main(){
//	
//	createfile();
//	readfile();
//
//                                Function is PASSING BY VALUE
//	
//
//void sum(int x){
//	x=x+30;
//	cout<<x<<endl;
//}
//int main(){
//	int a=90;
//	sum(a);
//	cout<<a<<endl;
//
//
//									POINTER ARRAY 
//
//	int arr[5];
//	for (int i=0; i<5; i++){
//		cin>>arr[i];
//	}
//	
//	cout<<arr<<endl;
//	cout<<*arr<<endl;
//	for (int i=0; i<5; i++){
//		cout<<*(arr+i)<<endl;
//	}	
//
//
//
//
//								ARRAY OF POINTER
//
//
//	int a=10 , b=60 , c=90;
//	int *ptr[3];
//	
//	ptr[0]=&a;
//	ptr[1]=&b;
//	ptr[2]=&c;
//	
//	for(int i=0; i<3; i++){
//		cout<<*ptr[i]<<endl;
//	}
//
//
//								ARRAY DECLARATION
//
//
//int arr[3]={10,20,30};
//int (*p)[3]=&arr;
//
//cout<<(*p)[0]<<endl;
//cout<<(*p)[1]<<endl;
//	
//	
//	
//							PRODUCT USING POINTER
//
//
//	int arr[3];
//	for (int i=0; i<3; i++){
//		cin>>arr[i];
//	}
//	int pro=1;
//	int *p=arr;
//	for(int i=0; i<3; i++){
//		pro*=*(p+i);
//	}
//	cout<<pro<<endl;
//
//
//							PRODUCT USING POINTER WITH FUNCTION
//
//
//	void pro(int arr[], int size ){
//		int pro=1;
//		int *p=arr;
//		for(int i=0; i<3; i++){
//		pro*=*(p+i);
//	}
//	cout<<pro<<endl;
//}
//
//	int main(){
//		
//		int arr[]={10,20,30,40,50};
//		int size=sizeof(arr)/sizeof(arr[0]);
//	
//	pro(arr,size);
//
//
//							PRODUCT USING POINTER WITH FUNCTION
//
//
//	void pro(int *ptr , int size){
//		int prod=1;
//		for(int i=0; i<size; i++){
//			prod*=*(ptr+i);
//		}
//		cout<<prod<<endl;
//	}
//int main(){
//
//	int arr[]={10,2,30,40};
//	int size=sizeof(arr)/sizeof(arr[0]);
//	
//	pro(arr , size);



	return 0;
}
