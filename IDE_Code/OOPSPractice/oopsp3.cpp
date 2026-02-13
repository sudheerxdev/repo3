#include <iostream>
#include <string>
using namespace std;

class Employee {
    
    // Private fields 
private:
    int id;
    string name;

public:

    // Setter methods
    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    // Getter methods
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }
};

int main() {
    Employee emp;

    // Using setters
    emp.setId(101);
    emp.setName("Geek");

    // Using getters
    cout << "Employee ID: " << emp.getId() << endl;
    cout << "Employee Name: " << emp.getName() << endl;

    return 0;
}
