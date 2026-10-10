#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void classifyWordLengths(string review) {
    int shortCount = 0;
    int mediumCount = 0;
    int longCount = 0;

    stringstream ss(review);
    string word;

    while (ss >> word) {
        int length = word.length();

        if (length >= 1 && length <= 4) {
            shortCount++;
        } else if (length <= 8) {
            mediumCount++;
        } else {
            longCount++;
        }
    }

    cout << "Short: " << shortCount
         << " | Medium: " << mediumCount
         << " | Long: " << longCount << endl;
}

int main() {
    classifyWordLengths("This movie was absolutely fantastic and thrilling");
    return 0;
}