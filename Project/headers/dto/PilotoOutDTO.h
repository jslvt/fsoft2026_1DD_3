#pragma once
#include <string>
using namespace std;

// Data Transfer Object for output — what the view displays to the user
struct PilotoOutDTO {
    int    id;
    string nome;
    string dataNasc;
    string nLicenca;
};
