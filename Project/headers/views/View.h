#pragma once
#include <string>
using namespace std;

// Base view — main menu and generic messages
class View {
public:
    View() = default;

    int  menuPrincipal();
    void printMessage(const string& msg);
    void printError(const string& msg);
    void pausar();
};
