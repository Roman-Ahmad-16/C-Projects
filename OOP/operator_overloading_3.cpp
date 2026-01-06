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

    Number operator ++ ()
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
    n.display();

    ++n;
    n.display();

    return 0;
}
