#include <iostream>
using namespace std;

class Order {
public:
    static int totalOrders;

    Order() {
        totalOrders++;
    }
};

int Order::totalOrders = 0;

int main() {
    Order o1;
    Order o2;
    Order o3;
    Order o4;

    cout << "Total orders: " << Order::totalOrders << endl;

    return 0;
}   