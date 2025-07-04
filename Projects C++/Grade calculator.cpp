#include<iostream>
using namespace std;
int main(){
	
	
	
/*90-100: A+
80-89: A
70-79: B
60-69: C
50-59: D
<50: F (Fail)*/


	
	cout << "Welcome to the Student Grade Calculator!" << endl;

	while(true){
		
		int marks;
		cout<<"Enter your marks(1 to 100) to check your grade = ";
		cin>>marks;
		
		if(marks>=90 && marks<=100){
			cout<<"Your Grade is :: A+"<<endl;
		}else if(marks>=80 && marks<=89){
			cout<<"Your Grade is :: A"<<endl;
		}else if(marks>=70 && marks<=79){
			cout<<"Your Grade is :: B"<<endl;
		}else if(marks>=60 && marks<=69){
			cout<<"Your Grade is :: C"<<endl;
		}else if(marks>=50 && marks<=59){
			cout<<"Your Grade is :: D"<<endl;
		} else if (marks >= 0 && marks < 50) {
            cout << "Your Grade is :: F" << endl;
        } else {
            cout << "Invalid marks. Please enter a value between 0 and 100." << endl;
        }
	}
	
	
	
	

	return 0;
}
