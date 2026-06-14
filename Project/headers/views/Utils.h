#pragma once
#include <string>
using namespace std;

class Utils {
public:
    // Read a non-empty string from stdin
    static string getString(const string& prompt);

    // Read a valid integer from stdin
    static int getNumber(const string& prompt);

    // Read a valid float from stdin
    static float getFloat(const string& prompt);

    // Read a date string validated as DD/MM/AAAA
    static string getDate(const string& prompt);

    // Read a licence number (3-20 alphanumeric/hyphens)
    static string getLicenca(const string& prompt);

    // Read a vehicle plate
    static string getMatricula(const string& prompt);

    // Read a year (1900-2100)
    static int getAno(const string& prompt);

    // Read a name (letters and spaces only, min 2 chars)
    static string getNome(const string& prompt);

    // Read a country name
    static string getPais(const string& prompt);

    // Read a position (>= 1)
    static int getPosicao(const string& prompt);

    // Read a time in seconds (> 0)
    static float getTempo(const string& prompt);
};