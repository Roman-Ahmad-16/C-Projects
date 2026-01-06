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
    void processPayment() 
    {
        cout << "Processing credit card payment with 2% fee " << endl;
    }
};
int main()
{
    Payment* p;
    CreditCard card;

    p = &card;
    p->processPayment();

    

    return 0;
}