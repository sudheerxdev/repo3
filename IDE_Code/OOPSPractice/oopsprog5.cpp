#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string brand;
    int year;

public:
    Vehicle(string b, int y) : brand(b), year(y) {}
    
    // Encapsulation with getters
    string getBrand() const { return brand; }
    int getYear() const { return year; }

    virtual void drive() const {
        cout << "The vehicle is driving" << endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int passengers;

public:
    Car(string b, int y, int p) : Vehicle(b, y), passengers(p) {}
    
    void drive() const override {
        cout << getBrand() << " car with " << passengers << " passengers is driving" << endl;
    }
};

class Truck : public Vehicle {
private:
    int loadCapacity;

public:
    Truck(string b, int y, int capacity) : Vehicle(b, y), loadCapacity(capacity) {}
    
    void drive() const override {
        cout << getBrand() << " truck carrying " << loadCapacity << " tons is driving" << endl;
    }
};

int main() {
    Vehicle* v1 = new Car("Toyota", 2020, 5);
    Vehicle* v2 = new Truck("Volvo", 2018, 10);
    
    v1->drive();  // Polymorphic call
    v2->drive();
    
    delete v1;
    delete v2;
    return 0;
}
