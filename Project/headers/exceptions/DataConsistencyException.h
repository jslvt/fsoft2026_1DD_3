#pragma once
#include <exception>
#include <string>
using namespace std;

// Thrown when removing something that is still referenced
// e.g. deleting a Piloto that has Participacoes
class DataConsistencyException : public exception {
private:
    string message;
public:
    explicit DataConsistencyException(const string& msg)
        : message("Data consistency error: " + msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
