#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Ticket {
protected:
    int count;
    static const double convenienceFee;

public:
    Ticket(int c) : count(c) {}

    virtual double calculateAmount() = 0;
    virtual string getSeat() = 0;

    virtual ~Ticket() {}
};

const double Ticket::convenienceFee = 20.0;

class Regular : public Ticket {
public:
    Regular(int c) : Ticket(c) {}

    double calculateAmount() override {
        return count * (150 + convenienceFee);
    }

    string getSeat() override {
        return "REGULAR";
    }
};

class Premium : public Ticket {
public:
    Premium(int c) : Ticket(c) {}

    double calculateAmount() override {
        return count * (250 + convenienceFee);
    }

    string getSeat() override {
        return "PREMIUM";
    }
};

class Recliner : public Ticket {
public:
    Recliner(int c) : Ticket(c) {}

    double calculateAmount() override {
        return count * (400 + convenienceFee);
    }

    string getSeat() override {
        return "RECLINER";
    }
};

int main() {
    int n, count;
    string seat;
    double total = 0;

    cin >> n;
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cin >> seat >> count;

        Ticket* ticket = nullptr;

        if (seat == "REGULAR")
            ticket = new Regular(count);
        else if (seat == "PREMIUM")
            ticket = new Premium(count);
        else if (seat == "RECLINER")
            ticket = new Recliner(count);

        if (ticket != nullptr) {
            double amount = ticket->calculateAmount();
            cout << ticket->getSeat() << ": " << amount << endl;
            total += amount;
            delete ticket;
        }
    }

    cout << "Total: " << total << endl;
    return 0;
}