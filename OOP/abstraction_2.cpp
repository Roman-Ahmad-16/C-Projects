#include <iostream>
using namespace std;
class Payment {
    public: 
        virtual bool validate() = 0;
        virtual void pay(double amount) = 0 ; 
    
    void processPayment(double amount) {
        if(validate()){
            pay(amount);
            cout<<"Payment Successful"<<endl;
        }else{
            cout<<"Payment Failed"<<endl;
        }
    }
    virtual ~Payment(){
        cout<<"Destroyed"<<endl;
    }
};

class CreditCardPayment : public Payment {
    public: 
        bool validate() override {
            cout<<"Validating Credit Card...."<<endl;
            return true;
        }
    void pay(double amount)override{
        cout<<"Paying "<<amount<<" using credit card"<<endl;
    }
};

class WalletPayment : public Payment {
    public:
        bool validate() override {
            cout<<"Checking Wallet Balance..."<<endl;
            return true;
        }

        void pay(double amount) override {
            cout<<"Paying"<<amount<<" using wallet"<<endl;
        }
};

int main(){
    Payment *p;

    CreditCardPayment C;
    WalletPayment W;

    p = &C;
    p->processPayment(5000);

     cout << "---------------------" << endl;

    p = &W;
    p->processPayment(3000);

    return 0;
}