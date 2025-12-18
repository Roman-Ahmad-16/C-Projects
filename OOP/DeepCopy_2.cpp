#include <iostream>
using namespace std;

class student
{
public:
    string name;
    string address;
    int *age;
    student(string n, string ad, int a)
    {
        name = n;
        address = ad;
        age = new int;
        *age = a;
    }

    student(student &s)
    {
        name = s.name;
        address = s.address;
        age = new int;
        *age = *s.age;
    }

    ~student()
    {
        delete age;
    }

    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
        cout << "Age : " << *age << endl;
    }
};

int main()
{
    student s1("Roman", "Ratta Road", 19);
    s1.display();
    student s2(s1);
    *(s2.age) = 20;
    s2.display();
    *(s1.age) = 40;
    s1.display();

    return 0;
}