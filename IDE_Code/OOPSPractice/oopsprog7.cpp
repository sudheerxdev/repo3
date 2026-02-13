#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function (abstract class)
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Rectangle(4, 5);
    shapes[1] = new Circle(3);

    for(int i = 0; i < 2; i++) {
        cout << "Area: " << shapes[i]->area() << endl;
        delete shapes[i];
    }
    return 0;
}
