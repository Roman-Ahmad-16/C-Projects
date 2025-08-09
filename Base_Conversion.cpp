#include<iostream>
using namespace std;

void base3(int n){
    if (n == 0)
	{
		return;
	} 
    base3(n / 3);
    cout << n % 3;
}

void base4(int n){
    if (n == 0)
	{
    	return;
	}
    base4(n / 4);
    cout << n % 4;
}

bool isPalindromeBase(int num, int base) {
    int temp = num;
    int reversed = 0, original = 0;
    int copy = num;

    while (copy > 0) {
        original = original * 10 + (copy % base);
        copy /= base;
    }

    int origCopy = original;
    while (origCopy > 0) {
        reversed = reversed * 10 + (origCopy % 10);
        origCopy /= 10;
    }

    return original == reversed;
}

int main() {
    int num;
    cout << "ENTER A NUMBER TO CONVERT IT INTO BASE 3 , 4 AND CHECK PALINDROME = ";
    cin >> num;

    cout << "BASE 3 = ";
    if (num == 0)
	{
		cout << "0";
	}
    else 
	{
		base3(num);
	}
    cout << "  -> Palindrome = " << (isPalindromeBase(num, 3) ? "YES" : "NO") << endl;

    cout << "BASE 4 = ";
    if (num == 0)
	{
		cout << "0";
	}
    else 
	{
		base4(num);
	}
    cout << "  -> Palindrome = " << (isPalindromeBase(num, 4) ? "YES" : "NO") << endl;

    return 0;
}  
