#include <iostream>
using namespace std;
class Staff
{
public:
    string name;
    void set_name(string n)
    {
        name = n;
    }

    virtual void calculateSalary() = 0;
    virtual void displayInfo() = 0;
};

class Doctor : public Staff
{
public:
    int monthlySalary;
    Doctor(int s)
    {
        monthlySalary = s;
    }

    void calculateSalary(){
        cout<<"Salary of doctor "<<name <<"is: "<<monthlySalary<<endl;
    }

    void displayInfo(){
        cout<<"Doctor name: "<<name<<endl;
    }
};

class Nurse : public Staff {
    public:
        int hours;
        int rate;

        Nurse(int h , int r){
            hours = h;
            rate = r;
        }

        void calculateSalary(){
            int salary;

            if(hours>160){
                salary = 160 * rate + (hours -160) * 20;
            }else{
                salary = hours+rate;
            }
            cout<<"Salary of Nurse "<<name<<"is: "<<salary<<endl;
        }

        void displayInfo(){
            cout<<"Nurse name: "<<name<<endl;
        }
};

int main(){

    Staff *s;

    Doctor d(80000);
    d.set_name("Dr.Ali");

    Nurse n(170,200);
    n.set_name("Sana");

    s = &d;
    s->displayInfo();
    s->calculateSalary();

    cout<<endl;

    s=&n;

    s->displayInfo();
    s->calculateSalary();

    return 0;
}