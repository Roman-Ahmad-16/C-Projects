#include <iostream>
using namespace std;

int main() {

  
    int pin=1234;
    int enterpin;
    int attempts;
    int max=3;
    
    while(true){
        cout << "Please enter your 4-digit PIN: ";
        cin>>enterpin;
        if(enterpin==pin){
            cout << "PIN validated successfully. Access granted!" << endl;
            break;
            
		}else{
			 attempts++;
			 if(attempts>max){
                cout << "Maximum attempts reached. Your account is locked. Please contact the bank." << endl;
                break;
                
                
			 }else{
			 	cout<<"Invalid pin you have "<<(max-attempts)<<"attempts left"<<endl;
			 }
		}
	}
    
        cout << "Thank you for using the ATM. Goodbye!" << endl;


    return 0;
}

