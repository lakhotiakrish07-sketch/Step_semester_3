#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Player {
private:
    string name;
    int matchesPlayed;
    double battingAverage;
    bool injured;

public:
    Player(string name, int matchesPlayed, double battingAverage, bool injured) {
        this->name = name;
        this->matchesPlayed = matchesPlayed;
        this->battingAverage = battingAverage;
        this->injured = injured;
    }

    static bool isDraftable(int matchesPlayed) {
        return matchesPlayed >= 10;
    }

    static bool isDraftable(int matchesPlayed, bool injured) {
        return matchesPlayed >= 5 && !injured;
    }

    bool qualifies() const {
        return isDraftable(matchesPlayed) ||
               isDraftable(matchesPlayed, injured);
    }

    string getName() const {
        return name;
    }

    bool operator<(const Player& other) const {
        return battingAverage > other.battingAverage;
    }

    static string draftAndRank(vector<Player>& players) {
        vector<Player> draftable;

        for (const Player& player : players) {
            if (player.qualifies()) {
                draftable.push_back(player);
            }
        }

        sort(draftable.begin(), draftable.end());

        string result = "";

        for (int i = 0; i < draftable.size(); i++) {
            if (i > 0)
                result += " | ";

            result += to_string(i + 1) + ". " + draftable[i].getName();
        }

        return result;
    }
};

int main() {
    vector<Player> players = {
        Player("Virat", 15, 48.0, false),
        Player("Rahul", 7, 55.0, false),
        Player("Sameer", 3, 60.0, false),
        Player("Dev", 12, 20.0, true)
    };

    cout << Player::draftAndRank(players) << endl;

    return 0;
}