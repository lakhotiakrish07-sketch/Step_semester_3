#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Appliance {
protected:
    double hours;
    static const double costPerUnit;

public:
    Appliance(double h) : hours(h) {}

    virtual double getPower() = 0;
    virtual bool supportsSaver() = 0;
    virtual string getName() = 0;

    virtual ~Appliance() {}

    double calculateUnits(bool saver) {
        double units = getPower() * hours / 1000.0;

        if (saver)
            units *= 0.75;

        return units;
    }

    double calculateCost(double units) {
        return units * costPerUnit;
    }
};

const double Appliance::costPerUnit = 8.0;

class Fridge : public Appliance {
public:
    Fridge(double h) : Appliance(h) {}

    double getPower() override {
        return 150;
    }

    bool supportsSaver() override {
        return false;
    }

    string getName() override {
        return "FRIDGE";
    }
};

class AC : public Appliance {
public:
    AC(double h) : Appliance(h) {}

    double getPower() override {
        return 1500;
    }

    bool supportsSaver() override {
        return true;
    }

    string getName() override {
        return "AC";
    }
};

class TV : public Appliance {
public:
    TV(double h) : Appliance(h) {}

    double getPower() override {
        return 100;
    }

    bool supportsSaver() override {
        return false;
    }

    string getName() override {
        return "TV";
    }
};

class Washer : public Appliance {
public:
    Washer(double h) : Appliance(h) {}

    double getPower() override {
        return 500;
    }

    bool supportsSaver() override {
        return true;
    }

    string getName() override {
        return "WASHER";
    }
};

int main() {
    int n;
    string type, mode;
    double hours, totalCost = 0;

    cin >> n;
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cin >> type >> hours;

        bool saver = false;
        if (cin.peek() == ' ') {
            string extra;
            cin >> extra;
            if (extra == "SAVER")
                saver = true;
        }

        Appliance* appliance = nullptr;

        if (type == "FRIDGE")
            appliance = new Fridge(hours);
        else if (type == "AC")
            appliance = new AC(hours);
        else if (type == "TV")
            appliance = new TV(hours);
        else if (type == "WASHER")
            appliance = new Washer(hours);

        if (appliance != nullptr) {
            if (saver && !appliance->supportsSaver()) {
                cout << appliance->getName()
                     << ": saver mode not supported" << endl;
            } else {
                double units = appliance->calculateUnits(saver);
                double cost = appliance->calculateCost(units);

                cout << appliance->getName()
                     << ": Units=" << units
                     << " Cost=" << cost << endl;

                totalCost += cost;
            }

            delete appliance;
        }
    }

    cout << "Total Cost: " << totalCost << endl;
    return 0;
}