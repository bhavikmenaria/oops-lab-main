#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    int employeeID;
    double salary;

public:
    Employee(const std::string& name, int employeeID, double initialSalary)
        : name(name), employeeID(employeeID), salary(initialSalary) {}

    void setSalaryBasedOnPerformance(double performanceRating) {
        if (performanceRating < 0 || performanceRating > 10) {
            std::cerr << "Invalid performance rating. It should be between 0 and 10." << std::endl;
            return;
        }

        if (performanceRating >= 8) {
            salary *= 1.10;  // 10% raise for high performance
        } else if (performanceRating >= 5) {
            salary *= 1.05;  // 5% raise for satisfactory performance
        } else {
            salary *= 0.95;  // 5% deduction for poor performance
        }
    }

    void displayEmployeeDetails() const {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Employee ID: " << employeeID << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
    }
};

int main() {
    Employee emp("Alice Johnson", 1001, 50000);

    emp.displayEmployeeDetails();

    emp.setSalaryBasedOnPerformance(9);  // High performance
    emp.displayEmployeeDetails();

    emp.setSalaryBasedOnPerformance(6);  // Satisfactory performance
    emp.displayEmployeeDetails();

    emp.setSalaryBasedOnPerformance(3);  // Poor performance
    emp.displayEmployeeDetails();

    return 0;
}
