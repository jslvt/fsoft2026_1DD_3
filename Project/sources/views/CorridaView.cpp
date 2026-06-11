#include "CorridaView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
using namespace std;

int CorridaView::menuCorridas() {
    int op = -1;
    do {
        cout << "\n\n---------- Menu Corridas ----------\n";
        cout << "1 - Adicionar\n";
        cout << "2 - Consultar\n";
        cout << "3 - Remover\n";
        cout << "4 - Atualizar\n";
        cout << "5 - Listar todas\n";
        cout << "6 - Listar por campeonato\n";
        cout << "7 - Associar a campeonato\n";
        cout << "8 - Desassociar de campeonato\n";
        cout << "\n0 - Voltar\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 8);
    return op;
}

CorridaInDTO CorridaView::getCorrida() {
    CorridaInDTO dto;
    cout << "\n-- Dados da Corrida --\n";
    dto.nome     = Utils::getString("Nome");
    dto.circuito = Utils::getString("Circuito");
    dto.data     = Utils::getString("Data (DD/MM/AAAA)");

    int tipo = -1;
    do {
        cout << "  Tipo (1 - Normal, 2 - Campeonato): ";
        tipo = Utils::getNumber("Tipo");
    } while (tipo < 1 || tipo > 2);
    dto.tipo = (tipo == 2) ? TipoCorrida::CAMPEONATO : TipoCorrida::NORMAL;

    return dto;
}

int CorridaView::getId() {
    return Utils::getNumber("ID da Corrida");
}

int CorridaView::getCampeonatoId() {
    return Utils::getNumber("ID do Campeonato");
}

void CorridaView::printCorrida(const CorridaOutDTO& dto) {
    cout << left
         << "[" << setw(3) << dto.id << "] "
         << setw(30) << dto.nome
         << "  Circuito: " << setw(20) << dto.circuito
         << "  Data: "     << setw(12) << dto.data
         << "  Tipo: "     << setw(12) << dto.tipoStr;
    if (dto.campeonatoId != 0)
        cout << "  Camp.: " << dto.campeonatoId;
    cout << "\n";
}

void CorridaView::printCorridas(list<CorridaOutDTO>& dtos) {
    if (dtos.empty()) {
        cout << "  Sem corridas registadas.\n";
        return;
    }
    cout << "\n-- Lista de Corridas --\n";
    cout << string(90, '-') << "\n";
    for (auto& dto : dtos)
        printCorrida(dto);
    cout << string(90, '-') << "\n";
}
