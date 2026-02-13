#include <iostream>
using namespace std;

// Abstract class Vehicle
class Vehicle {
public:

    // Abstract methods 
    virtual void accelerate() = 0;
    
    // pure virtual function
    virtual void brake() = 0;       

    void startEngine() {
        cout << "Engine started!" << endl;
    }
};

class Car : public Vehicle {
public:

    // Implement abstract methods
    void accelerate() override {
        cout << "Car: Pressing gas pedal..." << endl;
    }

    void brake() override {
        cout << "Car: Applying brakes..." << endl;
        
    }
};

int main() {
    
    // Create object using pointer to abstract class
    Vehicle* myCar = new Car();  
    myCar->startEngine();
    myCar->accelerate();
    myCar->brake();

    delete myCar; 
    return 0;
}
