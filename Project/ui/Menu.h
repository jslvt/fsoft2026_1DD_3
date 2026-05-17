#pragma once
#include <string>
#include <vector>

class Menu {
public:
    // Display a titled menu and return the user's validated choice (1..n)
    static int mostrarMenu(const std::string& titulo,
                           const std::vector<std::string>& opcoes);

    // Read a non-empty string from stdin
    static std::string lerString(const std::string& prompt);

    // Read an integer from stdin
    static int lerInt(const std::string& prompt);

    // Read a float from stdin
    static float lerFloat(const std::string& prompt);

    static void pausar();
    static void separador();
};
