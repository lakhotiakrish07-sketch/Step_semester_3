#include <iostream>
#include <vector>
#include <string>
using namespace std;

double rowAverage(vector<int>& row) {
    if (row.empty())
        return 0.0;

    int sum = 0;

    for (int runs : row) {
        sum += runs;
    }

    return static_cast<double>(sum) / row.size();
}

string classifyMatches(vector<vector<int>>& runsPerOver, int threshold) {
    string result = "";

    for (int i = 0; i < runsPerOver.size(); i++) {
        double average = rowAverage(runsPerOver[i]);

        if (i > 0)
            result += " | ";

        result += "Match " + to_string(i) + ": ";

        if (average >= threshold)
            result += "Power Surge";
        else
            result += "Normal";
    }

    return result;
}

int main() {
    vector<vector<int>> runsPerOver = {
        {4, 6, 8},
        {10, 12, 14},
        {2, 3, 1}
    };

    cout << classifyMatches(runsPerOver, 8) << endl;

    return 0;
}