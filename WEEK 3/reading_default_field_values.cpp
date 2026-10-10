#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string empName;
    double salary;
    bool permanent;
};

int main() {
    Employee e{};

    cout << "Name: " << (e.empName.empty() ? "null" : e.empName) << endl;
    cout << "Salary: " << e.salary << endl;
    cout << boolalpha << "Permanent: " << e.permanent << endl;

    return 0;
}