#include "VeiculoView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
using namespace std;

int VeiculoView::menuVeiculos() {
    int op = -1;
    do {
        cout << "\n\n---------- Menu Veiculos ----------\n";
        cout << "1 - Adicionar\n";
        cout << "2 - Consultar\n";
        cout << "3 - Remover\n";
        cout << "4 - Atualizar\n";
        cout << "5 - Listar todos\n";
        cout << "6 - Listar por equipa\n";
        cout << "7 - Associar a equipa\n";
        cout << "8 - Desassociar de equipa\n";
        cout << "\n0 - Voltar\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 8);
    return op;
}

VeiculoInDTO VeiculoView::getVeiculo() {
    VeiculoInDTO dto;
    cout << "\n-- Dados do Veiculo --\n";
    dto.modelo    = Utils::getString("Modelo");
    dto.matricula = Utils::getMatricula("Matricula (ex: AA-00-AA)");
    dto.ano       = Utils::getAno("Ano");
    return dto;
}

int VeiculoView::getId()       { return Utils::getNumber("ID do Veiculo"); }
int VeiculoView::getEquipaId() { return Utils::getNumber("ID da Equipa");  }

void VeiculoView::printVeiculo(const VeiculoOutDTO& dto) {
    cout << left
         << "[" << setw(3) << dto.id << "] "
         << setw(25) << dto.modelo
         << "  Matricula: " << setw(12) << dto.matricula
         << "  Ano: "       << setw(6)  << dto.ano;
    if (dto.equipaId == 0) cout << "  Equipa: (nenhuma)";
    else                   cout << "  Equipa: " << dto.equipaId;
    cout << "\n";
}

void VeiculoView::printVeiculos(list<VeiculoOutDTO>& dtos) {
    if (dtos.empty()) { cout << "  Sem veiculos registados.\n"; return; }
    cout << "\n-- Lista de Veiculos --\n";
    cout << string(75, '-') << "\n";
    for (auto& dto : dtos) printVeiculo(dto);
    cout << string(75, '-') << "\n";
}