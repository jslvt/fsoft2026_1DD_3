#pragma once
#include <list>
#include "Participacao.h"
using namespace std;

class ParticipacaoContainer {
private:
    list<Participacao> m_participacoes;

    // F1 points table positions 1..10
    static int calcPontos(int posicao);

public:
    ParticipacaoContainer() = default;

    // Add — throws DuplicatedDataException if piloto already in corrida
    // pontos calculated automatically based on posicao if isCampeonato=true
    void add(int pilotoId, int corridaId,
             int posicao, float tempo, bool isCampeonato);

    // Get single by piloto+corrida — throws NoDataException if not found
    Participacao* get(int pilotoId, int corridaId);

    // Get all participacoes for a corrida, sorted by posicao
    list<Participacao*> getByCorrida(int corridaId);

    // Get all participacoes for a piloto
    list<Participacao*> getByPiloto(int pilotoId);

    // Get all
    list<Participacao*> getAll();

    // Check if piloto has any participacao (used before removing piloto)
    bool hasPiloto(int pilotoId) const;

    // Check if corrida has any participacao (used before removing corrida)
    bool hasCorrida(int corridaId) const;

    // Remove single participation
    void remove(int pilotoId, int corridaId);

    // Update result
    void update(int pilotoId, int corridaId,
                int posicao, float tempo, bool isCampeonato);

    // Used by repository on load
    void restore(int pilotoId, int corridaId,
                 int posicao, float tempo, int pontos);
};
