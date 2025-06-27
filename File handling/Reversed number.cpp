#include<iostream>
using namespace std;

int main() {
    int number, a, b, c, d;
    
    cout << "Enter the three-digit number: " << endl;
    cin >> number;
    
    a = number / 100;          // Extract the first digit (hundreds place)
    b = number % 100;          // Get the last two digits
    c = b / 10;                // Extract the second digit (tens place)
    d = b % 10;                // Extract the third digit (ones place)
    cout << "Reversed number: " << d << c << a << endl;
    
    
    
    cout<<"ENTER 3 DIGIT FOR ADDITION "<<endl;
    cin>>number;
    
    a=number/100;
    b=number%100;
    c=b/10;
    d=b%10;
    cout<<a+c+d<<endl;
    
    
    cout<<"ENTER THREE DIGIT FOR MULTIPLICATION"<<endl;
    cin>>number;
    
    a=number/100;
    b=number%100;
    c=b/10;
    d=b%10;
    cout<<d*c*a<<endl;
    
    
 
    cout<<"ENTER THREE DIGIT FOR DIVISION"<<endl;
    cin>>number;
    
    a=number/100;
    b=number%100;
    c=b/10;
    d=b%10;
    cout<<d/c/a;
    
    return 0;
}

