#include "EquipaView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
using namespace std;

int EquipaView::menuEquipas() {
    int op = -1;
    do {
        cout << "\n\n---------- Menu Equipas ----------\n";
        cout << "1 - Adicionar\n";
        cout << "2 - Consultar\n";
        cout << "3 - Remover\n";
        cout << "4 - Atualizar\n";
        cout << "5 - Listar todas\n";
        cout << "6 - Adicionar piloto a equipa\n";
        cout << "7 - Remover piloto de equipa\n";
        cout << "\n0 - Voltar\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 7);
    return op;
}

EquipaInDTO EquipaView::getEquipa() {
    EquipaInDTO dto;
    cout << "\n-- Dados da Equipa --\n";
    dto.nome = Utils::getString("Nome");
    dto.pais = Utils::getString("Pais");
    return dto;
}

int EquipaView::getId() {
    return Utils::getNumber("ID da Equipa");
}

int EquipaView::getPilotoId() {
    return Utils::getNumber("ID do Piloto");
}

void EquipaView::printEquipa(const EquipaOutDTO& dto) {
    cout << left
         << "[" << setw(3) << dto.id << "] "
         << setw(30) << dto.nome
         << "  Pais: " << setw(20) << dto.pais;

    if (dto.pilotoIds.empty()) {
        cout << "  Pilotos: (nenhum)";
    } else {
        cout << "  Pilotos: ";
        for (int pid : dto.pilotoIds)
            cout << pid << " ";
    }
    cout << "\n";
}

void EquipaView::printEquipas(list<EquipaOutDTO>& dtos) {
    if (dtos.empty()) {
        cout << "  Sem equipas registadas.\n";
        return;
    }
    cout << "\n-- Lista de Equipas --\n";
    cout << string(70, '-') << "\n";
    for (auto& dto : dtos)
        printEquipa(dto);
    cout << string(70, '-') << "\n";
}
