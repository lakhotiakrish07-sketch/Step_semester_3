#include <iostream>
#include <string>
using namespace std;

class ExamHall {
public:
    string hallName;
    int seatsFilled = 0;
};

int main() {
    ExamHall hallA, hallB;

    hallA.hallName = "Block-3 Hall A";
    hallB.hallName = "Block-3 Hall B";

    hallA.seatsFilled++;
    hallA.seatsFilled++;
    hallA.seatsFilled++;
    hallA.seatsFilled++;

    cout << hallA.hallName << " seatsFilled: " << hallA.seatsFilled << endl;
    cout << hallB.hallName << " seatsFilled: " << hallB.seatsFilled << endl;

    return 0;
}