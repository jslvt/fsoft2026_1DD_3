#include "PilotoUI.h"
#include "Menu.h"
#include <iostream>

PilotoUI::PilotoUI(PilotoController& ctrl) : m_ctrl(ctrl) {}

void PilotoUI::criarPiloto() {
    std::cout << "\n=== Criar Piloto ===\n";
    std::string nome     = Menu::lerString("Nome");
    std::string dataNasc = Menu::lerString("Data de Nascimento (DD/MM/AAAA)");
    std::string nLicenca = Menu::lerString("Número de Licença");

    if (m_ctrl.criarPiloto(nome, dataNasc, nLicenca))
        std::cout << "  [OK] Piloto criado com sucesso.\n";
    else
        std::cout << "  [ERRO] Não foi possível criar o piloto.\n";

    Menu::pausar();
}

void PilotoUI::listarPilotos() {
    std::cout << "\n=== Lista de Pilotos ===\n";
    auto pilotos = m_ctrl.obterTodos();
    if (pilotos.empty()) {
        std::cout << "  Sem pilotos registados.\n";
    } else {
        Menu::separador();
        for (const auto& p : pilotos)
            p.print();
        Menu::separador();
    }
    Menu::pausar();
}
