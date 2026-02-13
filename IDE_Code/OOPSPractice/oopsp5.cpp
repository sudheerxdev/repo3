#include <iostream>
using namespace std;

// Parent Class
class Parent {
public:

    // Overloaded method 
    void func() {
        cout << "Parent.func()" << endl;
    }

    // Overloaded method 
    virtual void func(int a) {   
        cout << "Parent.func(int): " << a << endl;
    }
};

// Child Class
class Child : public Parent {
public:

    // Overrides Parent.func(int) 
    void func(int a) override {
        cout << "Child.func(int): " << a << endl;
    }
};

int main() {
    Parent parent;
    Child child;
    Parent* polymorphicObj = new Child();  

    // Method Overloading (compile-time)
    parent.func();        
    parent.func(10);     

    // Method Overriding (runtime)
    child.func(20);      

    // Polymorphism in action
    polymorphicObj->func(30);  

    delete polymorphicObj;  
    return 0;
}
