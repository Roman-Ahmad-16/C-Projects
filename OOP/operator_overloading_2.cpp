#include <iostream>
using namespace std;
class employee
{

public:
    int salary;
    employee(int s)
    {
        salary = s;
    }
    bool operator > (employee e)
    {
        return salary > e.salary;
    }
};
int main()
{

    employee e1(4000);
    employee e2(30000);
    employee e3(59093);

    if (e1 > e2 && e1 > e3)
    {
        cout << "E1 is greater" << endl;
    }
    else if (e2 > e1 && e2 > e3)
    {
        cout << "E2 is greater" << endl;
    }
    else if (e3 > e1 && e3 > e2)
    {
        cout << "E3 is greater" << endl;
    }
    else
    {
        cout << "Invalid salaries" << endl;
    }
    return 0;
}