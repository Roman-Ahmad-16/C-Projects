#include <iostream>
using namespace std;
class Number
{
public:
    int x;
    Number(int n)
    {
        x = n;
    }
    Number operator++(int)
    {
        Number n = *this;
        x = x + 1;
        return n;
    }

    void display()
    {
        cout << x<<endl;
    }
};
int main()
{
    Number nu(5);
    Number num = nu++;

    num.display();
    nu.display();

    return 0;
}