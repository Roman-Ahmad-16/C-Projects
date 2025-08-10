#include<iostream>
using namespace std;

struct Student 
{
	string name;
	int id;
	int marks[5];
	int total=500;
};
int main(){
	
	int obt_marks=0;
	Student st;
	
	cout<<"ENTER NAME OF STUDENT : "<<endl;
	cin>>st.name;
	
	cout<<"ENTER ID OF STUDENT : "<<endl;
	cin>>st.id;
	
	for(int i=0; i<5; i++){
		
		cin>>st.marks[i];
	obt_marks+=st.marks[i];
	
	if(st.marks[i]>=90){
			cout<<"GRADE IS A+ "<<endl;
		}else if(st.marks[i]>=80){
			cout<<"GRADE IS A "<<endl;
		}else if(st.marks[i]>=70){
			cout<<"GRADE IS B+ "<<endl;
		}else if(st.marks[i]>=60){
			cout<<"GRADE IS B "<<endl;
		}else if(st.marks[i]>=50){
			cout<<"GRADE IS C+ "<<endl;
		}else{
			cout<<"GRADE IS F "<<endl;
		}
	}
	
	float percentage = (obt_marks/(float)st.total)*100;
    cout << "YOUR PERCENTAGE = " << percentage << "%" << endl;
}
