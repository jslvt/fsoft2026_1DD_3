#include "VeiculoUI.h"
#include "Menu.h"
#include <iostream>

VeiculoUI::VeiculoUI(VeiculoController& ctrl) : m_ctrl(ctrl) {}

void VeiculoUI::criarVeiculo() {
    std::cout << "\n=== Criar Veiculo ===\n";
    std::string modelo    = Menu::lerString("Modelo");
    std::string matricula = Menu::lerString("Matricula");
    int         ano       = Menu::lerInt("Ano");

    if (m_ctrl.criarVeiculo(modelo, matricula, ano))
        std::cout << "  [OK] Veiculo criado com sucesso.\n";
    else
        std::cout << "  [ERRO] Nao foi possivel criar o veiculo.\n";

    Menu::pausar();
}

void VeiculoUI::listarVeiculos() {
    std::cout << "\n=== Lista de Veiculos ===\n";
    auto veiculos = m_ctrl.obterTodos();
    if (veiculos.empty()) {
        std::cout << "  Sem veiculos registados.\n";
    } else {
        Menu::separador();
        for (const auto& v : veiculos)
            v.print();
        Menu::separador();
    }
    Menu::pausar();
}
