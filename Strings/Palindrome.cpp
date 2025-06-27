#include"iostream"
using namespace std;
int main(){
	
	char str[50];
	int count=0;
	
	cin.getline(str,50); 
	
	for( int i=0; i<50; i++){
		if(str[i]=='\0'){
			break;
		}
		count++;
	}
	
	bool isPalindrome = true;
    for (int i = 0; i < count / 2; i++) {
        if (str[i] != str[count - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    
    
	return 0;
}
