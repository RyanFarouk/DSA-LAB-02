#include <iostream>
using namespace std;

class Employee {
public:
    virtual float calculateSalary() = 0;
};

class FullTimeEmployee : public Employee {
private:
    float salary;

public:
    FullTimeEmployee(float s) {
        salary = s;
    }

    float calculateSalary() {
        return salary;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    float hourlyRate;

public:
    PartTimeEmployee(int h, float r) {
        hoursWorked = h;
        hourlyRate = r;
    }

    float calculateSalary() {
        return hoursWorked * hourlyRate;
    }
};

int main() {
    FullTimeEmployee fullEmp(50000);
    PartTimeEmployee partEmp(20, 500);

    cout << "Full Time Employee Salary: " << fullEmp.calculateSalary() << endl;
    cout << "Part Time Employee Salary: " << partEmp.calculateSalary() << endl;

    return 0;
}