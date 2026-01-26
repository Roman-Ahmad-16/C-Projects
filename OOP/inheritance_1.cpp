// Inheritance (Is-A Relationship)
// Jab ek class doosri class ki cheezain use karti hai.

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
    string brand = "Honda";
    void honk()
    {
        cout << "Beep Beep !" << endl;
    }
};

class Car : public Vehicle
{
public:
    string model = "2024";
};

int main()
{
    Car mycar;
    mycar.honk();
    cout << mycar.brand << " " << mycar.model << endl;
    return 0;
}