#include <iostream>
using namespace std;

class student
{
public:
    string *name;
    int *age;
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

    ~student(){
        delete name;
        delete age;
    }
    
    void display()
    {
        cout << "Name : " << *name << endl;
        cout << "Age : " << *age << endl;
    }
};

int main()
{
    student s1("Roman", 19);
    s1.display();
    student s2(s1);
    *(s2.name) = "Ahmad";
    *(s2.age) = 20;
    s2.display();

    return 0;
}