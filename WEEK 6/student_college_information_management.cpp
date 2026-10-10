#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    double attendance;

    static string collegeName;
    static int studentCount;

    Student(string n, double a) {
        name = n;
        attendance = a;
        studentCount++;
    }

    static void printCollegeInfo() {
        cout << collegeName << endl;
        cout << "Students: " << studentCount << endl;
    }
};

string Student::collegeName = "SRM Institute of Science and Technology";
int Student::studentCount = 0;

int main() {
    Student s1("Ravi", 85.5);
    Student s2("Anitha", 92.0);

    Student::printCollegeInfo();

    return 0;
}