#include "VeiculoUI.h"
#include "Menu.h"
#include <iostream>

VeiculoUI::VeiculoUI(VeiculoController& ctrl) : m_ctrl(ctrl) {}

void VeiculoUI::criarVeiculo() {
    std::cout << "\n=== Criar Veículo ===\n";
    std::string modelo    = Menu::lerString("Modelo");
    std::string matricula = Menu::lerString("Matrícula");
    int         ano       = Menu::lerInt("Ano");

    if (m_ctrl.criarVeiculo(modelo, matricula, ano))
        std::cout << "  [OK] Veículo criado com sucesso.\n";
    else
        std::cout << "  [ERRO] Não foi possível criar o veículo.\n";

    Menu::pausar();
}

void VeiculoUI::listarVeiculos() {
    std::cout << "\n=== Lista de Veículos ===\n";
    auto veiculos = m_ctrl.obterTodos();
    if (veiculos.empty()) {
        std::cout << "  Sem veículos registados.\n";
    } else {
        Menu::separador();
        for (const auto& v : veiculos)
            v.print();
        Menu::separador();
    }
    Menu::pausar();
}
