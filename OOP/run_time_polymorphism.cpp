#include <iostream>
using namespace std;
class TollBooth
{

private:
    string id;
    double amount;

protected:
    static double collection;
    static int count;

public:
    TollBooth()
    {
        id = "None";
        amount = 0.0;
    }

   virtual void processVehicle(string id, double amount)
    {
        this->id = id;
        this->amount = amount;
        collection += amount;
        count++;
        cout << " Vehicle " << id << " processed Fee: $" << amount << endl;
    }

    static void displaystats()
    {
        cout << "Total count" << count << endl;
        cout << "Collection" << collection << endl;
    }
};

double TollBooth::collection = 0;
int TollBooth::count = 0;

class HeavyVehicleBooth : public TollBooth
{
public:
    void processVehicle(string id, double amount)
    {
        double tax = 50.0;
        double f_amount = amount + tax;

        TollBooth::processVehicle(id, f_amount);
        cout << id << " " << f_amount << endl;
    }
};

int main(){
    
    TollBooth alpha;
    TollBooth *currentBooth;
    HeavyVehicleBooth beta;
    currentBooth = &alpha;
    currentBooth->processVehicle("car-789" , 10.0);
    currentBooth->processVehicle("car-789" , 10.0);
    currentBooth = &beta;
    currentBooth->processVehicle("Truck-456" , 50.0);

    TollBooth::displaystats();

    return 0;
}