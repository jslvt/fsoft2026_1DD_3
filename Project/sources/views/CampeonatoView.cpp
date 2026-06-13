#include "CampeonatoView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
using namespace std;

int CampeonatoView::menuCampeonatos() {
    int op = -1;
    do {
        cout << "\n\n---------- Menu Campeonatos ----------\n";
        cout << "1 - Adicionar\n";
        cout << "2 - Consultar\n";
        cout << "3 - Remover\n";
        cout << "4 - Atualizar\n";
        cout << "5 - Listar todos\n";
        cout << "6 - Adicionar corrida ao campeonato\n";
        cout << "7 - Remover corrida do campeonato\n";
        cout << "8 - Inscrever equipa no campeonato\n";
        cout << "9 - Remover equipa do campeonato\n";
        cout << "10 - Ver classificacao\n";
        cout << "\n0 - Voltar\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 10);
    return op;
}

CampeonatoInDTO CampeonatoView::getCampeonato() {
    CampeonatoInDTO dto;
    cout << "\n-- Dados do Campeonato --\n";
    dto.nome = Utils::getString("Nome");
    dto.ano  = Utils::getNumber("Ano");
    return dto;
}

int CampeonatoView::getId()       { return Utils::getNumber("ID do Campeonato"); }
int CampeonatoView::getCorridaId(){ return Utils::getNumber("ID da Corrida");    }
int CampeonatoView::getEquipaId() { return Utils::getNumber("ID da Equipa");     }

void CampeonatoView::printCampeonato(const CampeonatoOutDTO& dto) {
    cout << left
         << "[" << setw(3) << dto.id << "] "
         << setw(30) << dto.nome
         << "  Ano: " << dto.ano;

    cout << "  Corridas: ";
    if (dto.corridaIds.empty()) cout << "(nenhuma)";
    else for (int id : dto.corridaIds) cout << id << " ";

    cout << "  Equipas: ";
    if (dto.equipaIds.empty()) cout << "(nenhuma)";
    else for (int id : dto.equipaIds) cout << id << " ";

    cout << "\n";
}

void CampeonatoView::printCampeonatos(list<CampeonatoOutDTO>& dtos) {
    if (dtos.empty()) { cout << "  Sem campeonatos registados.\n"; return; }
    cout << "\n-- Lista de Campeonatos --\n";
    cout << string(70, '-') << "\n";
    for (auto& dto : dtos) printCampeonato(dto);
    cout << string(70, '-') << "\n";
}

void CampeonatoView::printClassificacao(int campeonatoId,
                                         const string& campeonatoNome,
                                         list<pair<string, int>>& classificacao) {
    cout << "\n-- Classificacao: " << campeonatoNome << " (ID " << campeonatoId << ") --\n";
    cout << string(50, '-') << "\n";
    if (classificacao.empty()) {
        cout << "  Sem resultados registados.\n";
        cout << string(50, '-') << "\n";
        return;
    }
    int pos = 1;
    for (auto& [nome, pontos] : classificacao) {
        cout << "  " << setw(3) << pos++ << ".  "
             << setw(30) << nome
             << "  " << pontos << " pts\n";
    }
    cout << string(50, '-') << "\n";
}
