#pragma once
#include <string>
using namespace std;

class Utils {
public:
    // Read a non-empty string from stdin
    static string getString(const string& prompt);

    // Read a valid integer from stdin
    static int getNumber(const string& prompt);
};