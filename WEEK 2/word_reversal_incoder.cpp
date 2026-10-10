#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string reverseEachWord(string sentence) {
    stringstream ss(sentence);
    string word, result;

    while (ss >> word) {
        string reversed = "";

        for (int i = word.length() - 1; i >= 0; i--) {
            reversed += word[i];
        }

        if (!result.empty()) {
            result += " ";
        }

        result += reversed;
    }

    return result;
}

int main() {
    cout << reverseEachWord("hello club") << endl;
    return 0;
}