#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string normalizeCode(string raw) {
    size_t start = raw.find_first_not_of(" \t\n\r");
    if (start == string::npos) {
        return "";
    }

    size_t end = raw.find_last_not_of(" \t\n\r");
    string code = raw.substr(start, end - start + 1);

    if (code.length() >= 3) {
        for (int i = 0; i < 3; i++) {
            code[i] = toupper(static_cast<unsigned char>(code[i]));
        }
    }

    return code;
}

string validateAndFormat(string code) {
    if (code.length() != 13) {
        return "Invalid: code must be exactly 13 characters";
    }

    for (int i = 0; i < 3; i++) {
        if (!isalpha(static_cast<unsigned char>(code[i]))) {
            return "Invalid: publisher code must be 3 letters";
        }
    }

    for (int i = 3; i < 13; i++) {
        if (!isdigit(static_cast<unsigned char>(code[i]))) {
            return "Invalid: body must contain only digits";
        }
    }

    string year = code.substr(3, 4);
    string catalog = code.substr(7, 6);

    return "[" + code.substr(0, 3) + "] YEAR: "
           + year + " | CATALOG: " + catalog;
}

int main() {
    string raw = " pen2026004251 ";
    string code = normalizeCode(raw);

    cout << validateAndFormat(code) << endl;
    cout << validateAndFormat(normalizeCode("12N2026004251")) << endl;

    return 0;
}