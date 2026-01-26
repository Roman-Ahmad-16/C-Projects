// Aggregation ka matlab:
// School “has-a” Teacher, lekin Teacher independently exist karta hai.
// Real-life analogy:
// Teacher apni job chhor sakta hai
// School band ho sakta hai
// Dono ek dosray ke baghair bhi zinda reh sakte hain

#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
    string name = "Rashid";
};

class School
{
public:
    Teacher *t;
    void setTeacher(Teacher *obj)
    {
        t = obj;
    }

    void display()
    {
        cout << "Teacher is in this school: " << t->name << endl;
    }
};

int main()
{
    Teacher sir;
    School mySchool;

    mySchool.setTeacher(&sir);
    mySchool.display();

    return 0;
}