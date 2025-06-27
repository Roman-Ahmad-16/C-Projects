#include <iostream>
using namespace std;

int main() {
     
     int x=40 , y=90;
     int *p;
     
     p=&x;
     cout<<*p<<endl;
     
     p=&y;
     cout<<*p<<endl;

    return 0;
}

