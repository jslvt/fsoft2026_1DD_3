#include "../../headers/views/View.h"
#include "../../headers/views/Utils.h"
#include <iostream>
#include <limits>
using namespace std;

int View::menuPrincipal() {
    int op = -1;
    do {
        cout << "\n\n========== Gestao de Automobilismo ==========\n";
        cout << "1 - Pilotos\n";
        cout << "2 - Equipas\n";
        cout << "3 - Veiculos\n";
        cout << "4 - Corridas\n";
        cout << "5 - Participacoes\n";
        cout << "6 - Campeonatos\n";
        cout << "\n0 - Sair\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 6);
    return op;
}

void View::printMessage(const string& msg) {
    cout << "\n  [OK] " << msg << "\n";
}

void View::printError(const string& msg) {
    cout << "\n  [ERRO] " << msg << "\n";
}

void View::pausar() {
    cout << "\n  Prima ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}