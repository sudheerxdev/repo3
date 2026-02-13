#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string owner;
    double balance;

public:
    Account(string o, double b) : owner(o), balance(b) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << ", new balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn " << amount << ", new balance: " << balance << endl;
        }
    }

    virtual void display() const {
        cout << "Account owner: " << owner << ", balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string o, double b, double rate) : Account(o, b), interestRate(rate) {}

    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest added: " << interest << ", new balance: " << balance << endl;
    }

    void display() const override {
        Account::display();
        cout << "Interest rate: " << interestRate << "%" << endl;
    }
};

int main() {
    SavingsAccount sa("Alice", 1000, 5.0);
    sa.display();
    sa.deposit(500);
    sa.addInterest();
    sa.withdraw(200);
    sa.display();

    return 0;
}
