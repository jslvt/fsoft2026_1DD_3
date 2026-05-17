#include "EquipaUI.h"
#include "Menu.h"
#include <iostream>

EquipaUI::EquipaUI(EquipaController& ctrl) : m_ctrl(ctrl) {}

void EquipaUI::criarEquipa() {
    std::cout << "\n=== Criar Equipa ===\n";
    std::string nome = Menu::lerString("Nome da Equipa");
    std::string pais = Menu::lerString("País");

    if (m_ctrl.criarEquipa(nome, pais))
        std::cout << "  [OK] Equipa criada com sucesso.\n";
    else
        std::cout << "  [ERRO] Não foi possível criar a equipa.\n";

    Menu::pausar();
}

void EquipaUI::listarEquipas() {
    std::cout << "\n=== Lista de Equipas ===\n";
    auto equipas = m_ctrl.obterTodos();
    if (equipas.empty()) {
        std::cout << "  Sem equipas registadas.\n";
    } else {
        Menu::separador();
        for (const auto& e : equipas)
            e.print();
        Menu::separador();
    }
    Menu::pausar();
}
