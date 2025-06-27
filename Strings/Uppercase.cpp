//#include <iostream>
//using namespace std;
//
//int main() {
//    char str[50];
//    cin >> str;
//
//    for (int i = 0; i < 50; i++) {
//        if (str[i] == '\0') {
//            break;
//        }
//        if (str[i] >= 'a' && str[i] <= 'z') {
//            str[i] = str[i] - ('a' - 'A'); // Convert to uppercase
//        }
//    }
//
//    cout << "Uppercase: " << str << endl;
//    return 0;
//}




#include <iostream>
using namespace std;

int main() {

		char str[100];

		cout<<"ENTER A STRING = ";
		cin.getline(str,100);

		for( int i=0; str[i]!='\0'; i++){
			
			
			if(str[i]>='a' && str[i]<='z'){
				str[i]=str[i] - 32;
			}
		}

		cout<<"Upper case = "<<str;


    return 0;
}
