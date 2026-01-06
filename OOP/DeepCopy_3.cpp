#include <iostream>
using namespace std;
class student
{
private:
    string *name;
    int *age;

public:
    student(string n, int a)
    {
        name = new string;
        *name = n;
        age = new int;
        *age = a;
    }
    student(student &s)
    {
        name = new string;
        *name = *s.name;
        age = new int;
        *age = *s.age;
    }

    void setName(string n , int a)
    {
        *name = n;
        *age = a;
    }

    ~student()
    {
        delete name;
        delete age;
    }
    void display()
    {
        cout << *name << endl;
        cout << *age << endl;
    }
};
int main()
{
    student s1("Roman", 20);
    s1.display();

    student s2(s1);

    s2.setName("Ali" , 30);

    s2.display();
    return 0;
}