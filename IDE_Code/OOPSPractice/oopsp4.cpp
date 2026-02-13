#include <iostream>
using namespace std;

// Superclass (Parent)
class Animal {
public:
    void eat() {
        cout << "Animal is eating..." << endl;
    }

    void sleep() {
        cout << "Animal is sleeping..." << endl;
    }
};

// Subclass (Child) - Inherits from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking!" << endl;
    }
};

int main() {
    Dog myDog;

    // Inherited methods (from Animal)
    myDog.eat();
    myDog.sleep();

    // Child class method
    myDog.bark();

    return 0;
}
