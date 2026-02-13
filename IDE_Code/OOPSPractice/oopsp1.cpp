#include <iostream>
using namespace std;

// Encapsulation: class with private data members and public methods
class Animal {
private:
    string name;
public:
    Animal(string n) : name(n) {}
    
    void setName(string n) { name = n; }
    string getName() const { return name; }
    
    virtual void sound() const {  // Polymorphism via virtual function
        cout << "Some generic animal sound" << endl;
    }
};

// Inheritance: Dog and Cat inherit from Animal
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    
    void sound() const override {  // Polymorphism: override base method
        cout << getName() << " says Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    
    void sound() const override {  // Polymorphism: override base method
        cout << getName() << " says Meow!" << endl;
    }
};

int main() {
    Animal* a1 = new Dog("Buddy");
    Animal* a2 = new Cat("Whiskers");
    
    a1->sound();  // Outputs: Buddy says Woof!
    a2->sound();  // Outputs: Whiskers says Meow!
    
    delete a1;
    delete a2;
    return 0;
}
