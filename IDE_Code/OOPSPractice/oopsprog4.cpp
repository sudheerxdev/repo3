#include <iostream>
#include <string>
using namespace std;

// Base class: Encapsulation and Abstraction
class Animal {
private:
    string name;  // private data member, encapsulated
    
public:
    Animal(string n) : name(n) {}  // Constructor
    
    // Getter method to access private member
    string getName() const {
        return name;
    }
    
    // Virtual function for polymorphism
    virtual void sound() const {
        cout << "Animal makes a sound" << endl;
    }
    
    // Virtual destructor for safe polymorphic deletion
    virtual ~Animal() {}
};

// Derived class: Inheritance and Polymorphism
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}  // constructor
    
    // Override the base class method
    void sound() const override {
        cout << getName() << " says Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    
    void sound() const override {
        cout << getName() << " says Meow!" << endl;
    }
};

int main() {
    // Polymorphism in action using base class pointer
    Animal* animals[3];
    animals[0] = new Animal("Generic Animal");
    animals[1] = new Dog("Buddy");
    animals[2] = new Cat("Whiskers");
    
    for(int i = 0; i < 3; i++) {
        animals[i]->sound();   // Calls the appropriate sound() at runtime
    }
    
    for(int i = 0; i < 3; i++) {
        delete animals[i];  // Free allocated memory
    }
    
    return 0;
}
