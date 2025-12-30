#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    int accountNumber;
    
    static double interestRate;  
    static double totalCash;    
    static int accountCounter;       
public:
    
    BankAccount(string name, double initialDeposit) {
        accountHolder = name;
        balance = initialDeposit;
        accountNumber = ++accountCounter;
    
        totalCash += initialDeposit;
        
        cout << "Account created for " << name 
             << " (A/C: " << accountNumber 
             << ") with balance: $" << balance << endl;
    }
    
    ~BankAccount() {
        totalCash -= balance;  
        cout << "Account " << accountNumber << " closed." << endl;
    }
    
    void deposit(double amount) {
        balance += amount;
        totalCash += amount;
        cout << "$" << amount << " deposited to A/C " << accountNumber 
             << ". New balance: $" << balance << endl;
    }
    
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            totalCash -= amount;
            cout << "$" << amount << " withdrawn from A/C " << accountNumber 
                 << ". New balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance in A/C " << accountNumber << endl;
        }
    }
    
    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        totalCash += interest;
        cout << "Interest of $" << interest << " added to A/C " << accountNumber 
             << ". New balance: $" << balance << endl;
    }
    
    void display() const {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "----------------------\n" << endl;
    }
    
    static void setInterestRate(double newRate) {
        interestRate = newRate;
        cout << "\n*** Interest rate changed to " << newRate << "% for ALL accounts ***\n" << endl;
    }
    
    static void showBankStatus() {
        cout << "\n======= BANK STATUS =======" << endl;
        cout << "Total Accounts: " << accountCounter << endl;
        cout << "Total Cash: $" << totalCash << endl;
        cout << "Current Interest Rate: " << interestRate << "%" << endl;
        cout << "===========================\n" << endl;
    }
    
    int getAccountNumber() const {
        return accountNumber;
    }
};

double BankAccount::interestRate = 5.0;   
double BankAccount::totalCash = 0;      
int BankAccount::accountCounter = 0;    

int main() {
    cout << "=== BANK MANAGEMENT SYSTEM ===\n" << endl;
    
    BankAccount::showBankStatus();
    
    cout << "Creating accounts..." << endl;
    BankAccount acc1("Rahul Sharma", 5000);
    BankAccount acc2("Priya Patel", 10000);
    BankAccount acc3("Amit Kumar", 7500);
    
    BankAccount::showBankStatus();
    
    cout << "\n--- Transactions ---" << endl;
    acc1.deposit(2000);
    acc2.withdraw(3000);
    acc3.deposit(1500);
    
    BankAccount::showBankStatus();

    acc1.display();
    acc2.display();
    acc3.display();
    
    cout << "Bank manager changing interest rate..." << endl;
    BankAccount::setInterestRate(6.5);  // Changed to 6.5%
    
    cout << "Applying interest to all accounts..." << endl;
    acc1.applyInterest();
    acc2.applyInterest();
    acc3.applyInterest();
    
    BankAccount::showBankStatus();
    
    cout << "Bank manager changing interest rate again..." << endl;
    BankAccount::setInterestRate(7.0);  // Changed to 7%
    
    BankAccount::showBankStatus();
    
    cout << "\nProgram ending - accounts will be closed automatically" << endl;
    
    return 0;
}
