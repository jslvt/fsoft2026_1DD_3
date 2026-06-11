#pragma once
#include <string>
using namespace std;

// Data Transfer Object for input — what the view collects from the user
struct PilotoInDTO {
    string nome;
    string dataNasc;
    string nLicenca;
};