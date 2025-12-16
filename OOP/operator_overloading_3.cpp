#include <iostream>
using namespace std;

class Number
{
public:
    int value;

    Number(int v)
    {
        value = v;
    }

    Number operator++()
    {
        value = value + 1;
    }

    void display()
    {
        cout << "Value: " << value << endl;
    }
};

int main()
{
    Number n(5);
    Number n2(6);
    n.display();
    n2.display();

    ++n;
    ++n2;
    n.display();
    n2.display();

    return 0;
}
