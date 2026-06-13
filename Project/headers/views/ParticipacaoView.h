#pragma once
#include <list>
#include "ParticipacaoInDTO.h"
#include "ParticipacaoOutDTO.h"
using namespace std;

class ParticipacaoView {
public:
    ParticipacaoView() = default;

    int menuParticipacoes();

    ParticipacaoInDTO getParticipacao();
    int getPilotoId();
    int getCorridaId();

    void printParticipacao(const ParticipacaoOutDTO& dto);
    void printParticipacoes(list<ParticipacaoOutDTO>& dtos);
    void printClassificacaoGeral(list<pair<string, int>>& classificacao);
};
