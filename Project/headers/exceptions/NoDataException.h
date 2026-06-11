#pragma once
#include <exception>
#include <string>
using namespace std;

// Thrown when a lookup finds nothing
// e.g. get(id) where id does not exist
class NoDataException : public exception {
private:
    string message;
public:
    explicit NoDataException(const string& msg)
        : message("No data found: " + msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
