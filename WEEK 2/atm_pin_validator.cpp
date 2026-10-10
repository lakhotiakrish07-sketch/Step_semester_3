#include <iostream>
#include <string>
using namespace std;

void checkPinLength(string pin) {
    if (pin.length() != 4) {
        cout << "Invalid PIN - must be exactly 4 digits." << endl;
    } else {
        cout << "PIN length OK." << endl;
    }
}

int main() {
    checkPinLength("4820");
    return 0;
}