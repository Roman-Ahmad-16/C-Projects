#include <iostream>
using namespace std;

class Employee
{
private:
    int salary;
    string employeeID;

public:
    Employee(string id, int sal) : employeeID(id)
    {
        setSalary(sal);
    }

    void setSalary(int sal)
    {
        if (sal > 0)
        {
            salary = sal;
        }
        else
        {
            cout << "Invalid salary" << endl;
            salary = 0;
        }
    }

    int getSalary()
    {
        return salary;
    }

    string getEmployeeID()
    {
        return employeeID;
    }
};

int main()
{
    Employee emp("E134", 5000);

    cout << "Employee id " << emp.getEmployeeID() << endl;
    cout << "Initial salary " << emp.getSalary() << endl;

    emp.setSalary(-1000);
    cout << "Salary after invalid update: " << emp.getSalary() << endl;

    emp.setSalary(60000);
    cout << "Update Salary: " << emp.getSalary() << endl;

    return 0;
}