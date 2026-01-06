#include <iostream>
using namespace std;
class person
{
public:
    int x, y;

    person(int a, int b)
    {
        x = a;
        y = b;
    }
    person operator + (person c)
    {
        return person(x + c.x, y + c.y);
    }
    void display()
    {
        cout << x << " " << y << endl;
    }
};
int main()
{

    person p1(1, 9);
    person p2(4, 6);
    person p3(5, 90);
    person p4 = p1 + p2 + p3;
    p4.display();

    return 0;
}