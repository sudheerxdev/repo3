#include <iostream>
using namespace std;

class IVehicle {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~IVehicle() {}
};

class Bike : public IVehicle {
public:
    void start() override {
        cout << "Bike started" << endl;
    }
    void stop() override {
        cout << "Bike stopped" << endl;
    }
};

class Car : public IVehicle {
public:
    void start() override {
        cout << "Car started" << endl;
    }
    void stop() override {
        cout << "Car stopped" << endl;
    }
};

int main() {
    IVehicle* v1 = new Bike();
    IVehicle* v2 = new Car();

    v1->start();
    v2->start();

    v1->stop();
    v2->stop();

    delete v1;
    delete v2;
    return 0;
}
