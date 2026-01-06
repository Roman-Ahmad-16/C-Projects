#include <iostream>
using namespace std;

class Counter
{
public:
    int value;

    Counter(int v)
    {
        value = v;
    }

    Counter operator++(int)
    {
        Counter t = *this;
        value = value + 1;
        return t;
    }

    void display()
    {
        cout << "Value: " << value << endl;
    }
};

int main()
{
    Counter c1(5);
    Counter c2 = c1++;
    
    c2.display();
    c1.display();

    return 0;
}
