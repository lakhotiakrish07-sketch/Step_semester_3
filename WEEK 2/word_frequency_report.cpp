#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

void printFilteredWordFrequency(string feedback) {
    for (int i = 0; i < feedback.length(); i++) {
        feedback[i] = tolower(static_cast<unsigned char>(feedback[i]));

        if (ispunct(static_cast<unsigned char>(feedback[i]))) {
            feedback[i] = ' ';
        }
    }

    string stopWords[] = {"the", "was", "and", "a", "is", "of", "in"};
    map<string, int> frequency;
    stringstream ss(feedback);
    string word;

    while (ss >> word) {
        bool skip = false;

        for (string stop : stopWords) {
            if (word == stop) {
                skip = true;
                break;
            }
        }

        if (!skip) {
            frequency[word]++;
        }
    }

    vector<pair<string, int>> words(frequency.begin(), frequency.end());

    sort(words.begin(), words.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });

    for (auto item : words) {
        cout << item.first << ": " << item.second << endl;
    }
}

int main() {
    printFilteredWordFrequency(
        "The mentor was great, the session was great and clear."
    );

    return 0;
}