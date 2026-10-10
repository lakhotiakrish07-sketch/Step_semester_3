#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void checkTypingAccuracy(string original, string typed) {
    int matched = 0;
    int firstMismatch = -1;

    for (int i = 0; i < original.length(); i++) {
        if (original[i] == typed[i]) {
            matched++;
        } else if (firstMismatch == -1) {
            firstMismatch = i;
        }
    }

    double accuracy = (matched * 100.0) / original.length();

    cout << "Matched: " << matched << "/" << original.length();
    cout << " | Accuracy: " << fixed << setprecision(2)
         << accuracy << "% | ";

    if (firstMismatch == -1) {
        cout << "No Mismatches" << endl;
    } else {
        cout << "First Mismatch at position " << firstMismatch + 1
             << " ('" << original[firstMismatch]
             << "' vs '" << typed[firstMismatch] << "')" << endl;
    }
}

int main() {
    checkTypingAccuracy("hello world", "hello worlt");
    return 0;
}