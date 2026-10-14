#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Parcel {
protected:
    double weight, declaredValue;

public:
    Parcel(double w, double v) : weight(w), declaredValue(v) {}

    virtual double calculateCharge() = 0;
    virtual double calculateInsurance() {
        return 0;
    }

    virtual string getType() = 0;
    virtual ~Parcel() {}
};

class Standard : public Parcel {
public:
    Standard(double w, double v) : Parcel(w, v) {}

    double calculateCharge() override {
        return 40 + 10 * weight;
    }

    string getType() override {
        return "STANDARD";
    }
};

class Express : public Parcel {
public:
    Express(double w, double v) : Parcel(w, v) {}

    double calculateCharge() override {
        return 80 + 15 * weight;
    }

    double calculateInsurance() override {
        return declaredValue * 0.02;
    }

    string getType() override {
        return "EXPRESS";
    }
};

class Fragile : public Parcel {
public:
    Fragile(double w, double v) : Parcel(w, v) {}

    double calculateCharge() override {
        return 40 + 10 * weight + 50;
    }

    double calculateInsurance() override {
        return declaredValue * 0.02;
    }

    string getType() override {
        return "FRAGILE";
    }
};

int main() {
    int n;
    string type;
    double weight, value, grandTotal = 0;

    cin >> n;
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cin >> type >> weight >> value;

        Parcel* parcel = nullptr;

        if (type == "STANDARD")
            parcel = new Standard(weight, value);
        else if (type == "EXPRESS")
            parcel = new Express(weight, value);
        else if (type == "FRAGILE")
            parcel = new Fragile(weight, value);

        if (parcel != nullptr) {
            double charge = parcel->calculateCharge();
            double insurance = parcel->calculateInsurance();
            double total = charge + insurance;

            cout << parcel->getType()
                 << ": Charge=" << charge
                 << " Insurance=" << insurance
                 << " Total=" << total << endl;

            grandTotal += total;
            delete parcel;
        }
    }

    cout << "Grand Total: " << grandTotal << endl;
    return 0;
}