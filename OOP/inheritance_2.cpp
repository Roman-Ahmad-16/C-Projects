// Composition (Has-A - Strong)
// Jab ek class ke andar doosri class ka object banate hain. Agar main class khatam ho jaye,
//  toh andar wali class bhi khatam ho jati hai. Example: "Mobile" ke andar "Battery" hoti hai.

#include <iostream>
using namespace std;

class Battery
{
public:
    void power()
    {
        cout << "Battery is 100%" << endl;
    }
};

class Mobile
{
public:
    Battery bat;

    void show()
    {
        cout << "Mobile is on." << endl;
        bat.power();
    }
};

int main()
{
    Mobile m;
    m.show();

    return 0;
}