#include <iostream>
using namespace std;

void checkDuplicateSeats(int seatNumbers[], int n) {
    bool found = false;

    for (int i = 0; i < n; i++) {
        bool alreadyPrinted = false;

        for (int k = 0; k < i; k++) {
            if (seatNumbers[i] == seatNumbers[k]) {
                alreadyPrinted = true;
                break;
            }
        }

        if (alreadyPrinted)
            continue;

        for (int j = i + 1; j < n; j++) {
            if (seatNumbers[i] == seatNumbers[j]) {
                cout << "Duplicate Seat Number Found: "
                     << seatNumbers[i] << endl;
                found = true;
                break;
            }
        }
    }

    if (!found)
        cout << "No Duplicate Seats Found" << endl;
}

int main() {
    int seats[] = {101, 102, 103, 102, 105};
    int n = sizeof(seats) / sizeof(seats[0]);

    checkDuplicateSeats(seats, n);
    return 0;
}