#pragma once
#include <list>
#include "IRacingRepository.h"
#include "ParticipacaoInDTO.h"
#include "ParticipacaoOutDTO.h"
using namespace std;

class ParticipacaoService {
private:
    IRacingRepository* m_repo;

    // Resolve names from ids for DTO display
    string getPilotoNome(int pilotoId);
    string getCorridaNome(int corridaId);
    bool   isCampeonato(int corridaId);

public:
    explicit ParticipacaoService(IRacingRepository* repo);

    // Register a result — validates piloto and corrida exist
    void add(const ParticipacaoInDTO& dto);

    // Get classification for a corrida (sorted by posicao)
    void getByCorrida(int corridaId, list<ParticipacaoOutDTO>& dtos);

    // Get all results for a piloto
    void getByPiloto(int pilotoId, list<ParticipacaoOutDTO>& dtos);

    // Get total points per piloto across all campeonato corridas
    // Returns list of pairs (pilotoNome, totalPontos) sorted desc
    list<pair<string, int>> getClassificacaoGeral();

    // Remove a participation
    void remove(int pilotoId, int corridaId);

    // Update a result
    void update(const ParticipacaoInDTO& dto);
};
