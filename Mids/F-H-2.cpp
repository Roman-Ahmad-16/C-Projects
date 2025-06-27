#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main(){
	
								SUM USING POINTERS 
	
	int arr[]={10,20,30,40};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	int sum=0;
	int *ptr=arr;
	for(int i=0; i<size; i++){
		sum+=*(ptr+i);
	}
	cout<<sum<<endl;

							REVERSED CHARACTER ARRAY USING POINTER

	char arr[10] , *ptr, temp;
	cout<<"ENTER CHARACTER ARRAY :: "<<endl;
	cin>>arr;
	
	int i=0;
	while(arr[i]!='\0'){
		i++;
	}
	cout<<"length of array = "<<i<<endl;

	ptr=arr;
	for(int j=0; j<i; j++){
		temp=*ptr;
		*ptr=arr[i-1];
		arr[i-1]=temp;
		ptr++;
		i--;
	}
	cout<<"reverse char array :: "<<arr<<endl;

									max and minimum using pointers

	int maxvalue(int *ptr , int size){
		
		int *max=ptr;
		for(int i=1; i<size; i++){
			if(*(ptr+i)>*max){
				max=ptr+i;
			}
		}
		return *max;
	}
	
	int minivalue(int *ptr , int size){
		
		int *mini=ptr;
		for(int i=1; i<size; i++){
			if(*(ptr+i)<*mini){
				mini=ptr+i;
			}
		}
		return *mini;
	}
	
	int main(){
	
	int size;
	cout<<"ENTER THE SIZE OF ARRAY = ";
	cin>>size;
	
	int arr[size];
	int *ptr=arr;
	for(int i=0; i<size; i++){
		cout<<"VALUE OF ARRAY AT THE INDEX = "<<i<<" ";
		cin>>*(ptr+i);
	}
	ptr=arr;

    cout << "Maximum : " << maxvalue(ptr, size) << endl;
    cout << "Minimum : " << minivalue(ptr, size) << endl;


													smaller to greater number sorting

	int arr[5]; 
	int temp;
	cout<<"ENTER ARAY VALUES ";	
	for(int i=0; i<5; i++){
		cin>>arr[i];
	}
	
	cout<<"VALUES BEFORE SORTING "<<endl;
	for(int b=0; b<5; b++){
		cout<<" "<<arr[b]<<endl;
	}
	
	for(int j=0; j<5; j++){
		for(int k=j+1; k<5; k++){
			if(arr[j]>arr[k]){
				temp=arr[j];
				arr[j]=arr[k];
				arr[k]=temp;
			}
		}
	}

	cout<<"VALUES AFTER SORTING"<<endl;
	for(int e=0; e<5; e++){
		cout<<" "<<arr[e]<<endl;
	}
	
/													 greater  to smaller  number sorting

	int arr[5]; 
	int temp;
	cout<<"ENTER ARAY VALUES ";	
	for(int i=0; i<5; i++){
		cin>>arr[i];
	}
	
	cout<<"VALUES BEFORE SORTING "<<endl;
	for(int b=0; b<5; b++){
		cout<<" "<<arr[b]<<endl;
	}
	
	for(int j=0; j<5; j++){
		for(int k=j+1; k<5; k++){
			if(arr[j]<arr[k]){
				temp=arr[j];
				arr[j]=arr[k];
				arr[k]=temp;
			}
		}
	}

	cout<<"VALUES AFTER SORTING"<<endl;
	for(int e=0; e<5; e++){
		cout<<" "<<arr[e]<<endl;
	}

				convert seconds in to hours and minutes 

	int s ;
	cin>>s;
	
	int h;
	h=s/3600;
	
	int se;
	se=s%3600;
	
	int min;
	min=se/60;
	
	int sec;
	sec=se%60;
	
	cout<<h<<":"<<min<<":"<<sec;

				 Reversed number

	int a,b,c,d,num;
	cin>>num;
	
	a=num/100;
	b=num%100;
	c=b/10;
	d=b%10;
	
	cout<<d<<c<<a<<endl;
	cout<<a+c+d<<endl;
	cout<<d+c+a<<endl;
	cout<<d/c/a<<endl;
	

							ARMSTRING NUMBER

	int num;
	cin>>num;

	int on=num;
	int result=0;
	int remainder;
	
	while(on!=0){
		remainder=on%10;
		result+=remainder*remainder*remainder;\
		on/=10;
	}
	if(result==num){
		cout<<"armstrong"<<endl;
	}
	else{
		cout<<"not";
	}

												BUBBLE SORT 

    int arr[5], temp;

    cout << "Enter the values of an array" << endl;
    for(int j = 0; j < 5; j++) {
        cin >> arr[j];
    }

    cout << "Array before sorting" << endl;
    for(int j = 0; j < 5; j++) {
        cout << arr[j] << " "; 
    }
    cout << endl;

	for (int i=0; i<5; i++){
		for(int j=0; j<4; j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

    cout << "Array after sorting" << endl;
    for(int n = 0; n < 5; n++) {
        cout << arr[n] << " "; 
    }
    cout << endl;


									PALINDROME WITH CSTRING

	int palindrome(char str[]){
		char b[100];
		strcpy(b , str);
		strrev(b);
		if(strcmp(str,b)==0){
			return 1;
		}
		else{
			return 0;
		}			
	}
	

	int main(){
	
	char a[10];
	char b[10];
	
	cin>>a;

	if(palindrome(a)){
		cout<<"palindrome"<<endl;
	}
	else{
		cout<<"not"<<endl;
	}

						Takes a sentence input from the user.Writes it to a file.Reads the file character by character.Counts the number of vowels.Displays the vowel count.

	int vowelscount=0;
	char ch[20];
    cin.getline(ch,20);
     
	ofstream file("vowels.txt");
	file<<ch;
	file.close();
	
	ifstream read("vowels.txt");
	char c;
	while(read.get(c)){
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            	vowelscount++;
			}
	}
	cout<<vowelscount<<endl;



 				Create a file and store char array data in file

 char data1[50], data2[50];

    ofstream write("lab3_1.txt");

    for (int i = 1; i <= 2; i++) {
        cout << "Enter your name: ";
        cin >> data1;
        cout << "Enter your roll no: ";
        cin >> data2;

        write << i << "\t" << data1 << "\t" << data2 << endl;
    }

    write.close(); 


	return 0;
}
