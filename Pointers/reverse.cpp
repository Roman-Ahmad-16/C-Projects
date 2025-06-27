#include<iostream>
using namespace std;

int main()
{
    char ch[50], *ptr;
    cout << "\nEnter the Char Array: ";
    cin >> ch;

    int i = 0;
    while (ch[i] != '\0')
    {
        i++;
    }

    ptr = ch;
    char temp;

    cout << "\nBefore reverse array is: " << ch;

    for (int j = 0; j < i/2 ; j++)
    {
        temp = *ptr;
        *ptr = ch[i - 1];
        ch[i - 1] = temp;
        ptr++;
        i--;
    }

    cout << "\nAfter reverse array is: " << ch;

    return 0;
}
