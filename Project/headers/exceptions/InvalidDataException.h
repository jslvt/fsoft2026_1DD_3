#pragma once
#include <exception>
#include <string>
using namespace std;

// Thrown when input data fails validation
// e.g. empty name, invalid year, negative position
class InvalidDataException : public exception {
private:
    string message;
public:
    explicit InvalidDataException(const string& msg)
        : message("Invalid data: " + msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
