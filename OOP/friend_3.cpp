#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    void setNumber(int n, int n1)
    {
        a = n;
        b = n1;
    }

    friend complex operator + (complex c1, complex c2);

    void printNumber()
    {
        cout << "Your Number Is " << a << " + " << b << "i" << endl;
    }
};

complex operator + (complex c1, complex c2)
{
    complex o3;
    o3.a = c1.a + c2.a;
    o3.b = c1.b + c2.b;
    // o3.setNumber((c1.a + c2.a), (c1.b + c2.b));
    return o3;
}
int main()
{
    complex c1, c2;
    c1.setNumber(1, 4);
    c1.printNumber();

    c2.setNumber(5, 8);
    c2.printNumber();

    complex c3 = c1 + c2 ;
    c3.printNumber();

    return 0;
}