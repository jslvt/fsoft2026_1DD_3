#pragma once
#include <string>
using namespace std;

struct ParticipacaoOutDTO {
    int    pilotoId;
    int    corridaId;
    int    posicao;
    float  tempo;
    int    pontos;
    // Denormalised fields filled by service for display
    string pilotoNome;
    string corridaNome;
};
