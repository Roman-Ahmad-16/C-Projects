#include <iostream>
using namespace std;

class Payment
{
public:
    virtual void processPayment()
    {
        cout << "Processing Generic payment" << endl;
    }
};

class CreditCard : public Payment
{
public:
    void processPayment() override
    {
        cout << "Processing credit card payment with 2% fee " << endl;
    }
};
int main()
{
    CreditCard card;
    cout << "Calling overriden method: " << endl;
    card.processPayment();

    cout << "Calling base class method using scope resolution: " << endl;
    card.Payment::processPayment();

    return 0;
}