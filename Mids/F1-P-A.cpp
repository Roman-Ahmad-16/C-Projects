//#include <iostream>
//using namespace std;
//
////// Function with one parameter
////void greet(string name) {  // 'name' is a parameter
////    cout << "Hello, " << name << "!" << endl;
////}
////
////int main() {
////    greet("Alice");  // "Alice" is an argument
////    greet("Bob");    // "Bob" is another argument
//
//
//void add(int a , int b){
//	cout<<"SUM = "<<a+b<<endl;
//}
//
//
//void multiply(int c , int d){
//	cout<<"Multiply = "<<c*d<<endl;
//}
//
//
//int main(){
//
//	add(4,6);
//	add(78,89);
//
//	multiply(2,5);
//	multiply(34,89); 
//	
//	
//    return 0;
//}



#include <iostream>
using namespace std;

void greet(int a =45 ,  int b=45) {
    cout << "Sum =  " << a+b << endl;
}

int main() {
    greet();           // Uses default
    greet(2,6);     // Uses provided argument
    return 0;
}

