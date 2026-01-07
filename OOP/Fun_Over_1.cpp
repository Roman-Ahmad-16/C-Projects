#include <iostream>
using namespace std;
class Number
{
public:
    void show(int x)
    {
        cout << x << endl;
    }

    void show(char ch)
    {
        cout << ch << endl;
    }
};
int main()
{
    Number n;
    n.show('f');

    return 0;
}

// THIS IA AN EXAMPLE OF POLYMORFISM (COMPILE TIME POLYMORFISM )