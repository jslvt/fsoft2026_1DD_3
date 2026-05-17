#include "CorridaUI.h"
#include "Menu.h"
#include <iostream>

CorridaUI::CorridaUI(CorridaController& ctrl) : m_ctrl(ctrl) {}

void CorridaUI::criarCorrida() {
    std::cout << "\n=== Criar Corrida ===\n";
    std::string nome     = Menu::lerString("Nome da Corrida");
    std::string circuito = Menu::lerString("Circuito");
    std::string data     = Menu::lerString("Data (DD/MM/AAAA)");

    if (m_ctrl.criarCorrida(nome, circuito, data))
        std::cout << "  [OK] Corrida criada com sucesso.\n";
    else
        std::cout << "  [ERRO] Não foi possível criar a corrida.\n";

    Menu::pausar();
}

void CorridaUI::listarCorridas() {
    std::cout << "\n=== Lista de Corridas ===\n";
    auto corridas = m_ctrl.obterTodos();
    if (corridas.empty()) {
        std::cout << "  Sem corridas registadas.\n";
    } else {
        Menu::separador();
        for (const auto& c : corridas)
            c.print();
        Menu::separador();
    }
    Menu::pausar();
}
