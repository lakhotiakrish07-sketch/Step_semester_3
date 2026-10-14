#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    double tuition;
    static const double transportFee;

public:
    Student(string n, double t) : name(n), tuition(t) {}

    virtual double calculateFee() = 0;
    virtual ~Student() {}

    string getName() {
        return name;
    }
};

const double Student::transportFee = 12000.0;

class DayScholar : public Student {
public:
    DayScholar(string n) : Student(n, 40000) {}

    double calculateFee() override {
        return tuition + transportFee;
    }
};

class Hosteller : public Student {
public:
    Hosteller(string n) : Student(n, 40000) {}

    double calculateFee() override {
        return tuition + 60000;
    }
};

class Scholar : public Student {
public:
    Scholar(string n) : Student(n, 20000) {}

    double calculateFee() override {
        return tuition + transportFee;
    }
};

int main() {
    int n;
    string type, name;
    double total = 0;

    cin >> n;
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cin >> type >> name;

        Student* student = nullptr;

        if (type == "DAY_SCHOLAR")
            student = new DayScholar(name);
        else if (type == "HOSTELLER")
            student = new Hosteller(name);
        else if (type == "SCHOLAR")
            student = new Scholar(name);

        if (student != nullptr) {
            double fee = student->calculateFee();
            cout << student->getName() << ": " << fee << endl;
            total += fee;
            delete student;
        }
    }

    cout << "Total Collected: " << total << endl;
    return 0;
}