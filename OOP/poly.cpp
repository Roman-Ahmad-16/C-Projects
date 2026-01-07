#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void calculateTime(double distance)
    {
        double time = distance / 60;
        cout << "\n[Normal Car] Speed: 60 km/h" << endl;
        cout << "Estimated Time: " << time << " hours." << endl;
    }
};

class SuperBike : public Vehicle
{
public:
    void calculateTime(double distance)
    {
        double time = distance / 120;
        cout << "\n[SuperBike] Speed: 120 km/h (Fast Mode!)" << endl;
        cout << "Estimated Time: " << time << " hours." << endl;
    }
};

class LoaderTruck : public Vehicle
{
public:
    void calculateTime(double distance)
    {
        double time = distance / 30;
        cout << "\n[LoaderTruck] Speed: 30 km/h (Heavy Load)" << endl;
        cout << "Estimated Time: " << time << " hours." << endl;
    }
};

int main()
{
    double distance;
    int choice;

    Vehicle *ptr = NULL;

    cout << "--- Highway Travel Calculator ---" << endl;
    cout << "Enter Total Distance (in km): ";
    cin >> distance;

    cout << "\nSelect Vehicle Type:" << endl;
    cout << "1. Normal Car" << endl;
    cout << "2. SuperBike" << endl;
    cout << "3. LoaderTruck" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        ptr = new Vehicle();
    }
    else if (choice == 2)
    {
        ptr = new SuperBike();
    }
    else if (choice == 3)
    {
        ptr = new LoaderTruck();
    }
    else
    {
        cout << "Invalid Choice! Defaulting to Normal Car." << endl;
        ptr = new Vehicle();
    }

    ptr->calculateTime(distance);

    delete ptr;

    return 0;
}