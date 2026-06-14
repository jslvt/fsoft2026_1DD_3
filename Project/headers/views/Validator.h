#pragma once
#include <string>
using namespace std;

// Static helper class with all validation logic.
// Used by both Views (before sending to service)
// and Model setters (as a second line of defence).
class Validator {
public:
    // Date in format DD/MM/AAAA
    // Returns true if valid, false otherwise
    static bool isDateValid(const string& date);

    // Licence number: 3-20 alphanumeric chars, hyphens allowed
    static bool isLicencaValid(const string& licenca);

    // Plate: 6-8 alphanumeric chars, hyphens allowed (e.g. AA-00-AA)
    static bool isMatriculaValid(const string& matricula);

    // Year: between 1900 and 2100
    static bool isAnoValid(int ano);

    // Name: at least 2 chars, no digits
    static bool isNomeValid(const string& nome);

    // Country: at least 2 chars
    static bool isPaisValid(const string& pais);

    // Position: >= 1
    static bool isPosicaoValid(int posicao);

    // Time in seconds: > 0
    static bool isTempoValid(float tempo);

    // Error messages for each rule
    static string dateError();
    static string licencaError();
    static string matriculaError();
    static string anoError();
    static string nomeError();
    static string paisError();
    static string posicaoError();
    static string tempoError();
};