#include "Utils.h"
#include <iostream>
#include <limits>
using namespace std;

string Utils::getString(const string& prompt) {
    string value;
    while (true) {
        cout << "  " << prompt << ": ";
        getline(cin, value);
        if (!value.empty()) return value;
        cout << "  [Erro] Campo obrigatorio. Tente novamente.\n";
    }
}

int Utils::getNumber(const string& prompt) {
    int value;
    while (true) {
        cout << "  " << prompt << ": ";
        cin >> value;
        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  [Erro] Numero invalido. Tente novamente.\n";
    }
}
