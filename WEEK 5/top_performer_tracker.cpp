#include <iostream>
#include <vector>
#include <string>
using namespace std;

string findMinMaxSpread(vector<int>& scores) {
    int minScore = scores[0];
    int maxScore = scores[0];

    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] < minScore)
            minScore = scores[i];

        if (scores[i] > maxScore)
            maxScore = scores[i];
    }

    return "Min: " + to_string(minScore) +
           " | Max: " + to_string(maxScore) +
           " | Spread: " + to_string(maxScore - minScore);
}

int main() {
    vector<int> scores = {45, 82, 79, 90, 33, 90, 61};

    cout << findMinMaxSpread(scores) << endl;

    return 0;
}