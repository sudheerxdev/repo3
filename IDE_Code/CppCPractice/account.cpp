#include <iostream>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double b) : balance(b) {}
    virtual void withdraw(double amount) {
        if(amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }
    double getBalance() const { return balance; }
    virtual ~Account() {}
};

class CheckingAccount : public Account {
    double fee;
public:
    CheckingAccount(double b, double f) : Account(b), fee(f) {}
    void withdraw(double amount) override {
        if(amount + fee <= balance) {
            balance -= (amount + fee);
            cout << "Withdrawn: " << amount << " with fee: " << fee << endl;
        } else {
            cout << "Insufficient balance including fee" << endl;
        }
    }
};

int main() {
    CheckingAccount ca(1000, 5);
    ca.withdraw(100);
    cout << "Balance: " << ca.getBalance() << endl;
    return 0;
}
