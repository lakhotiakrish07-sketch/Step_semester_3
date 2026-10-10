#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class PlacementRecord {
    string studentName, company;
    double packageLpa;

public:
    PlacementRecord(string name, string comp, double pkg) {
        studentName = name;
        company = comp;
        packageLpa = pkg;
    }

    void printRecord() {
        cout << studentName << " -> " << company << " @ "
             << fixed << setprecision(1) << packageLpa << " LPA" << endl;
    }
};

int main() {
    PlacementRecord records[] = {
        PlacementRecord("Ravi", "TCS", 4.5),
        PlacementRecord("Anitha", "Zoho", 6.2),
        PlacementRecord("Karthik", "Infosys", 4.0)
    };

    for (PlacementRecord record : records) {
        record.printRecord();
    }

    return 0;
}