#include <iostream>
#include <string>
using namespace std;

class IdCard {
public:
    string name;
    int booksIssued;

    IdCard(string n, int books) {
        name = n;
        booksIssued = books;
    }
};

int main() {
    IdCard ravi("Ravi", 0);

    IdCard* duplicate = &ravi;
    duplicate->booksIssued = 3;

    IdCard separate("Ravi", 3);

    cout << "Ravi's booksIssued (via first variable): "
         << ravi.booksIssued << endl;

    cout << boolalpha;
    cout << "duplicate == ravi: " << (duplicate == &ravi) << endl;
    cout << "separate == ravi: " << (&separate == &ravi) << endl;

    return 0;
}