#include "Menu.h"
#include <iostream>
#include <limits>
#include <sstream>

static const std::string LINE(50, '-');

int Menu::mostrarMenu(const std::string& titulo,
                      const std::vector<std::string>& opcoes)
{
    int escolha = 0;
    do {
        std::cout << "\n" << LINE << "\n";
        std::cout << "  " << titulo << "\n";
        std::cout << LINE << "\n";
        for (int i = 0; i < static_cast<int>(opcoes.size()); ++i)
            std::cout << "  [" << (i + 1) << "] " << opcoes[i] << "\n";
        std::cout << LINE << "\n";
        std::cout << "  Opcao: ";
        std::cin >> escolha;
        if (std::cin.fail()) {
            std::cin.clear();
            escolha = -1;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (escolha < 1 || escolha > static_cast<int>(opcoes.size()));
    return escolha;
}

std::string Menu::lerString(const std::string& prompt) {
    std::string valor;
    while (true) {
        std::cout << "  " << prompt << ": ";
        std::getline(std::cin, valor);
        if (!valor.empty()) return valor;
        std::cout << "  [Erro] Campo obrigatório. Tente novamente.\n";
    }
}

int Menu::lerInt(const std::string& prompt) {
    int valor;
    while (true) {
        std::cout << "  " << prompt << ": ";
        std::cin >> valor;
        if (!std::cin.fail()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  [Erro] Valor inteiro inválido. Tente novamente.\n";
    }
}

float Menu::lerFloat(const std::string& prompt) {
    float valor;
    while (true) {
        std::cout << "  " << prompt << ": ";
        std::cin >> valor;
        if (!std::cin.fail()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  [Erro] Valor decimal inválido. Tente novamente.\n";
    }
}

void Menu::pausar() {
    std::cout << "\n  Prima ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::separador() {
    std::cout << LINE << "\n";
}
