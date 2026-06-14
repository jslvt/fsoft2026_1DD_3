#include "ParticipacaoView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
using namespace std;

int ParticipacaoView::menuParticipacoes() {
    int op = -1;
    do {
        cout << "\n\n---------- Menu Participacoes ----------\n";
        cout << "1 - Registar resultado\n";
        cout << "2 - Classificacao por corrida\n";
        cout << "3 - Resultados por piloto\n";
        cout << "4 - Classificacao geral (pontos)\n";
        cout << "5 - Remover resultado\n";
        cout << "6 - Atualizar resultado\n";
        cout << "\n0 - Voltar\n";
        op = Utils::getNumber("Opcao");
    } while (op < 0 || op > 6);
    return op;
}

ParticipacaoInDTO ParticipacaoView::getParticipacao() {
    ParticipacaoInDTO dto;
    cout << "\n-- Dados da Participacao --\n";
    dto.pilotoId  = Utils::getNumber("ID do Piloto");
    dto.corridaId = Utils::getNumber("ID da Corrida");
    dto.posicao   = Utils::getPosicao("Posicao final");
    dto.tempo     = Utils::getTempo("Tempo (segundos, ex: 5432.5)");
    return dto;
}

int ParticipacaoView::getPilotoId()  { return Utils::getNumber("ID do Piloto");  }
int ParticipacaoView::getCorridaId() { return Utils::getNumber("ID da Corrida"); }

void ParticipacaoView::printParticipacao(const ParticipacaoOutDTO& dto) {
    cout << left
         << "  " << setw(4)  << dto.posicao
         << setw(28) << dto.pilotoNome
         << "  Corrida: " << setw(25) << dto.corridaNome
         << "  Tempo: "   << fixed << setprecision(3) << setw(10) << dto.tempo << "s"
         << "  Pontos: "  << dto.pontos
         << "\n";
}

void ParticipacaoView::printParticipacoes(list<ParticipacaoOutDTO>& dtos) {
    if (dtos.empty()) { cout << "  Sem resultados.\n"; return; }
    cout << "\n" << string(85, '-') << "\n";
    cout << left << setw(6) << "  Pos" << setw(28) << "Piloto"
         << setw(27) << "  Corrida" << setw(12) << "  Tempo(s)"
         << "  Pontos\n";
    cout << string(85, '-') << "\n";
    for (auto& dto : dtos) printParticipacao(dto);
    cout << string(85, '-') << "\n";
}

void ParticipacaoView::printClassificacaoGeral(list<pair<string, int>>& classificacao) {
    if (classificacao.empty()) { cout << "  Sem dados de campeonato.\n"; return; }
    cout << "\n-- Classificacao Geral (Campeonato) --\n";
    cout << string(45, '-') << "\n";
    int pos = 1;
    for (auto& [nome, pontos] : classificacao)
        cout << "  " << setw(3) << pos++ << ".  "
             << setw(30) << nome << "  " << pontos << " pts\n";
    cout << string(45, '-') << "\n";
}