#include <iostream>
using namespace std;

class Student
{
private:
    int id;
    string name;

public:
    static int totalStudents;

    void setData(int i, string n)
    {
        id = i;
        name = n;
        totalStudents++;
    }

    void showData()
    {
        cout << "Name : " << name << " , ID : " << id << endl;
    }

    static void showTotal()
    {
        cout << "Total Students : " << totalStudents << endl;
    }
};

int Student::totalStudents = 0;

int main()
{
    Student s[3];

    s[0].setData(295, "Roman");
    s[1].setData(296, "Ali");
    s[2].setData(297, "Abdullah");

    cout << "Student Records : " << endl;

    for (int i = 0; i < 3; i++)
    {
        s[i].showData();
    }

    Student::showTotal();

    return 0;
}