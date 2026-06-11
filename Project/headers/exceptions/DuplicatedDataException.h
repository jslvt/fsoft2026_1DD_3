#pragma once
#include <exception>
#include <string>
using namespace std;

// Thrown when trying to add something that already exists
// e.g. duplicate licence number
class DuplicatedDataException : public exception {
private:
    string message;
public:
    explicit DuplicatedDataException(const string& msg)
        : message("Duplicated data: " + msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
