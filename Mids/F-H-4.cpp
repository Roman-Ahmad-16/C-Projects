#include <iostream>
#include <cstdlib> 
#include<fstream>
#include<cstring>
using namespace std;
int main() {
	
	
					 Create, Input, Display, and Deallocate a Dynamic 2D Array


    int rows = 3, cols = 3;
    int **arr = new int*[rows];
    
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    
    cout << "Enter the values in an array" << endl;
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int m = 0; m < rows; m++) {
        for(int n = 0; n < cols; n++) {
            cout << arr[m][n] << "\t";
        }
        cout << endl;
    }
    
    for(int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;


			 Input and Display a 2D Array with console clearing after each row”


	int a , b;
	cin>>a;
	cin>>b;
	
	int arr[a][b];
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cin>>arr[i][j];
		}
	}

	system("cls");
	
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}


					AUTOMATIC FILL NUMBERS IN 2D ARRAYS 

    int rows = 3, cols = 3;
    int **arr = new int*[rows];
    
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    
    cout << "Enter the values in an array" << endl;
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
             arr[i][j]=i*cols+j;
        }
    }
    
    for(int m = 0; m < rows; m++) {
        for(int n = 0; n < cols; n++) {
            cout << arr[m][n] << "\t";
        }
        cout << endl;
    }
    
    for(int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    
   													 CALL BY VALUE 

	int add(int a , int b){
		return a+b;
	}
	
	int add1(int *p , int *m){
		return (*p)+(*m);
	}
int main(){

    int x , y;
    cin>>x>>y;
    
    cout<<add(x,y)<<endl;
    cout<<add1(&x,&y);
    
    
Create a C++ program that reads a list of names (as strings) from a file,
stores them into an array of character arrays (2D char array), and then writes
all names in reverse order into another file.

    
    const int MAX_NAME =100;
    const int MAX_SIZE=50;
    
    char names[MAX_NAME][MAX_SIZE];
    int count=0;
    
    ifstream infile("input.txt");
    while(infile>>names[count] && count<MAX_NAME){
    	count++;
	}
	infile.close();
	
	ofstream outfile("output.txt");
	for(int i=count-1; i>=0; i--){
		outfile<<names[i]<<endl;
	}
	outfile.close();
	
	cout << "Names have been successfully reversed in output.txt" << endl;



							SWAPING WITH POINTERS
	
	int x , y ;
	
    int *a = &x ;
    int *b = &y ;
    cin>>*a>>*b;
    
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
    
    cout<<*a<<"\t"<<*b<<endl;
    
    
    							SWAPING WITH POINTERS with third variable
  
  
   	int x , y ;
	
    int *a = &x ;
    int *b = &y ;
    cin>>*a>>*b;
    
    int temp;
    
    temp=*a;
    *a=*b;
    *b=temp;
    
    cout<<*a<<*b<<endl;


									STRING CAT
    
    
    char str1[]={'e','r'};
    char str2[]={'p','o'};
    
    cout<<strcat(str1,str2);



			find character



	char str[] = "hello";

    char *found = strchr(str, 'l');    

    if (found) {
        cout << "Character found at index: " << (found - str) << endl;
    } else {
        cout << "Not found!" << endl;
    }
    
    
    
    
    					find substring
   
   
   
   char str[]="roamnahamd";
   
   char *result=strstr(str,"ahamd");
   
   if(result){
        cout << "Substring found at: " << result << endl;
   }
   else {
   	cout<<"not"<<endl;
   }
   
    
    return 0;
} 
