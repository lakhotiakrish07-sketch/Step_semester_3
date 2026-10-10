#include <iostream>
#include <string>
using namespace std;

void findLongestStreak(string signalLog) {
    int maxCount = 1;
    int count = 1;
    char maxColor = signalLog[0];

    for (int i = 1; i < signalLog.length(); i++) {
        if (signalLog[i] == signalLog[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            maxColor = signalLog[i];
        }
    }

    cout << "Longest Streak: '" << maxColor
         << "' repeated " << maxCount << " times" << endl;
}

int main() {
    findLongestStreak("RRGGGYRR");
    return 0;
}