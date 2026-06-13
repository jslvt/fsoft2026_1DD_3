#pragma once
#include <list>
#include "IRacingRepository.h"
#include "CampeonatoInDTO.h"
#include "CampeonatoOutDTO.h"
using namespace std;

class CampeonatoService {
private:
    IRacingRepository* m_repo;

    string getPilotoNome(int pilotoId);
    string getCorridaNome(int corridaId);

public:
    explicit CampeonatoService(IRacingRepository* repo);

    void add(const CampeonatoInDTO& dto);
    void getAll(list<CampeonatoOutDTO>& dtos);
    void get(int id, CampeonatoOutDTO& dto);
    void remove(int id);
    void update(int id, const CampeonatoInDTO& dto);

    // Associate corridas and equipas
    void addCorrida(int campeonatoId, int corridaId);
    void removeCorrida(int campeonatoId, int corridaId);
    void addEquipa(int campeonatoId, int equipaId);
    void removeEquipa(int campeonatoId, int equipaId);

    // Championship standings — sum points from all corridas in campeonato
    list<pair<string, int>> getClassificacao(int campeonatoId);
};
