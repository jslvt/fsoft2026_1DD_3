#include "PilotoView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
using namespace std;

int PilotoView::menuPilotos() {
    int op = -1;
    do {
        cout << "\n\n---------- Menu Pilotos ----------\n";
        cout << "1 - Adicionar\n";
        cout << "2 - Consultar\n";
        cout << "3 - Remover\n";
        cout << "4 - Atualizar\n";
        cout << "5 - Listar todos\n";
        cout << "\n0 - Voltar\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 5);
    return op;
}

PilotoInDTO PilotoView::getPiloto() {
    PilotoInDTO dto;
    cout << "\n-- Dados do Piloto --\n";
    dto.nome     = Utils::getString("Nome");
    dto.dataNasc = Utils::getString("Data de Nascimento (DD/MM/AAAA)");
    dto.nLicenca = Utils::getString("Numero de Licenca");
    return dto;
}

int PilotoView::getId() {
    return Utils::getNumber("ID do Piloto");
}

void PilotoView::printPiloto(const PilotoOutDTO& dto) {
    cout << left
         << "[" << setw(3) << dto.id << "] "
         << setw(30) << dto.nome
         << "  Nasc: " << setw(12) << dto.dataNasc
         << "  Licenca: " << dto.nLicenca
         << "\n";
}

void PilotoView::printPilotos(list<PilotoOutDTO>& dtos) {
    if (dtos.empty()) {
        cout << "  Sem pilotos registados.\n";
        return;
    }
    cout << "\n-- Lista de Pilotos --\n";
    cout << string(70, '-') << "\n";
    for (auto& dto : dtos)
        printPiloto(dto);
    cout << string(70, '-') << "\n";
}