#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class Cab {
protected:
    double km;
    static const double minimumFare;

public:
    Cab(double distance) : km(distance) {}

    virtual double calculateFare(string time) = 0;
    virtual bool supportsNight() = 0;
    virtual string getType() = 0;

    virtual ~Cab() {}

    double baseFare(double rate) {
        return max(minimumFare, km * rate);
    }
};

const double Cab::minimumFare = 100.0;

class Mini : public Cab {
public:
    Mini(double distance) : Cab(distance) {}

    double calculateFare(string time) override {
        return baseFare(10);
    }

    bool supportsNight() override {
        return false;
    }

    string getType() override {
        return "MINI";
    }
};

class Sedan : public Cab {
public:
    Sedan(double distance) : Cab(distance) {}

    double calculateFare(string time) override {
        double fare = baseFare(14);
        if (time == "NIGHT")
            fare *= 1.2;
        return fare;
    }

    bool supportsNight() override {
        return true;
    }

    string getType() override {
        return "SEDAN";
    }
};

class SUV : public Cab {
public:
    SUV(double distance) : Cab(distance) {}

    double calculateFare(string time) override {
        double fare = baseFare(18);
        if (time == "NIGHT")
            fare *= 1.2;
        return fare;
    }

    bool supportsNight() override {
        return true;
    }

    string getType() override {
        return "SUV";
    }
};

int main() {
    int n;
    string type, time;
    double km, total = 0;

    cin >> n;
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cin >> type >> km >> time;

        Cab* cab = nullptr;

        if (type == "MINI")
            cab = new Mini(km);
        else if (type == "SEDAN")
            cab = new Sedan(km);
        else if (type == "SUV")
            cab = new SUV(km);

        if (cab != nullptr) {
            if (time == "NIGHT" && !cab->supportsNight()) {
                cout << cab->getType()
                     << ": night service not available" << endl;
            } else {
                double fare = cab->calculateFare(time);
                cout << cab->getType() << ": " << fare << endl;
                total += fare;
            }

            delete cab;
        }
    }

    cout << "Total: " << total << endl;
    return 0;
}