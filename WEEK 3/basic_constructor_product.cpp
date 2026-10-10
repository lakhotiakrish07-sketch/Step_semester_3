#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string productId;
    string productName;

    Product(string productId, string productName) {
        this->productId = productId;
        this->productName = productName;
    }
};

int main() {
    Product p("P-1042", "Wireless Mouse");

    cout << p.productId << " - " << p.productName << endl;

    return 0;
}