#include "Utils.h"
#include "Validator.h"
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

float Utils::getFloat(const string& prompt) {
    float value;
    while (true) {
        cout << "  " << prompt << ": ";
        cin >> value;
        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  [Erro] Valor invalido. Tente novamente.\n";
    }
}

string Utils::getDate(const string& prompt) {
    string value;
    while (true) {
        cout << "  " << prompt << " (DD/MM/AAAA): ";
        getline(cin, value);
        if (Validator::isDateValid(value)) return value;
        cout << "  [Erro] " << Validator::dateError() << "\n";
    }
}

string Utils::getLicenca(const string& prompt) {
    string value;
    while (true) {
        cout << "  " << prompt << ": ";
        getline(cin, value);
        if (Validator::isLicencaValid(value)) return value;
        cout << "  [Erro] " << Validator::licencaError() << "\n";
    }
}

string Utils::getMatricula(const string& prompt) {
    string value;
    while (true) {
        cout << "  " << prompt << ": ";
        getline(cin, value);
        if (Validator::isMatriculaValid(value)) return value;
        cout << "  [Erro] " << Validator::matriculaError() << "\n";
    }
}

int Utils::getAno(const string& prompt) {
    int value;
    while (true) {
        value = getNumber(prompt);
        if (Validator::isAnoValid(value)) return value;
        cout << "  [Erro] " << Validator::anoError() << "\n";
    }
}

string Utils::getNome(const string& prompt) {
    string value;
    while (true) {
        cout << "  " << prompt << ": ";
        getline(cin, value);
        if (Validator::isNomeValid(value)) return value;
        cout << "  [Erro] " << Validator::nomeError() << "\n";
    }
}

string Utils::getPais(const string& prompt) {
    string value;
    while (true) {
        cout << "  " << prompt << ": ";
        getline(cin, value);
        if (Validator::isPaisValid(value)) return value;
        cout << "  [Erro] " << Validator::paisError() << "\n";
    }
}

int Utils::getPosicao(const string& prompt) {
    int value;
    while (true) {
        value = getNumber(prompt);
        if (Validator::isPosicaoValid(value)) return value;
        cout << "  [Erro] " << Validator::posicaoError() << "\n";
    }
}

float Utils::getTempo(const string& prompt) {
    float value;
    while (true) {
        value = getFloat(prompt);
        if (Validator::isTempoValid(value)) return value;
        cout << "  [Erro] " << Validator::tempoError() << "\n";
    }
}