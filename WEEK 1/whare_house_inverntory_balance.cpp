#include <iostream>
using namespace std;

void analyzeInventory(int sectionA[], int sectionB[], int n) {
    int totalA = 0, totalB = 0;
    int maxQuantity = sectionA[0];
    string section = "Section A";
    int index = 0;

    for (int i = 0; i < n; i++) {
        totalA += sectionA[i];
        totalB += sectionB[i];

        if (sectionA[i] > maxQuantity) {
            maxQuantity = sectionA[i];
            section = "Section A";
            index = i;
        }

        if (sectionB[i] > maxQuantity) {
            maxQuantity = sectionB[i];
            section = "Section B";
            index = i;
        }
    }

    string status = (totalA == totalB) ? "Balanced" : "Not Balanced";

    cout << "Section A Total: " << totalA
         << " | Section B Total: " << totalB
         << " | Status: " << status
         << " | Highest Quantity: " << maxQuantity
         << " (" << section << ", Item " << index + 1 << ")" << endl;
}

int main() {
    int sectionA[] = {20, 15, 30};
    int sectionB[] = {25, 10, 30};

    analyzeInventory(sectionA, sectionB, 3);
    return 0;
}