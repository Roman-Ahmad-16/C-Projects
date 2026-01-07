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
    Number operator-()
    {
        x = -(x);
        return x;
    }
    void display()
    {
        cout << x << endl;
    }
};
int main()
{
    Number n(5);
    n.display();
    Number n2 = -(n);
    n2.display();
}