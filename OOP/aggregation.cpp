#include <iostream>
using namespace std;
class Teacher
{
public:
    string name;
    int id;
    Teacher(string n, int i)
    {
        name = n;
        id = i;
        cout << "Teacher created: " << name << ", ID: " << id << endl;
    }
    ~Teacher()
    {
        cout << "Teacher destroyed: " << name << endl;
    }
    void teach()
    {
        cout << name << " is teaching." << endl;
    }
};
class Department
{
public:
    string deptName;
    int deptID;
    Teacher *t; // Aggregation: pointer to Teacher
    Department(string dn, int di, Teacher *temp)
    {
        deptName = dn;
        deptID = di;
        t = temp; // link to existing Teacher
        cout << "Department created: " << deptName << ", ID: " << deptID << endl;
    }
    ~Department()
    {
        cout << "Department destroyed: " << deptName << endl;
        // Do NOT delete t; Teacher exists independently
    }
    void work()
    {
        cout << deptName << " department is using Teacher: ";
        t->teach();
    }
};
int main()
{
    Teacher t1("Ali", 101);                    // Step 1: Teacher created independently
    Department d1("Computer Science", 1, &t1); // Step 2: Department uses Teacher
    d1.work();                                 // Department uses T cout << "End of main" << endl;
}
