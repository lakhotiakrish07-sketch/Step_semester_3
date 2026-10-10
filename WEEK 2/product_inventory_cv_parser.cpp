#include <iostream>
#include <string>
using namespace std;

void parseInventoryRecord(string csvLine) {
    string fields[3];
    int count = 0;
    int start = 0;

    for (int i = 0; i <= csvLine.length(); i++) {
        if (csvLine[i] == ',' || i == csvLine.length()) {
            if (count < 3) {
                fields[count] = csvLine.substr(start, i - start);
            }

            count++;
            start = i + 1;
        }
    }

    if (count != 3) {
        cout << "Invalid Record" << endl;
    } else {
        cout << "Product: " << fields[0]
             << " | SKU: " << fields[1]
             << " | Qty: " << fields[2] << endl;
    }
}

int main() {
    parseInventoryRecord("Wireless Mouse,WM-2201,150");
    parseInventoryRecord("Wireless Mouse,150");
    return 0;
}