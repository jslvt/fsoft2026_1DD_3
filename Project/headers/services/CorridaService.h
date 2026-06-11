#pragma once
#include <list>
#include "IRacingRepository.h"
#include "CorridaInDTO.h"
#include "CorridaOutDTO.h"
using namespace std;

class CorridaService {
private:
    IRacingRepository* m_repo;

public:
    explicit CorridaService(IRacingRepository* repo);

    void add(const CorridaInDTO& dto);
    void getAll(list<CorridaOutDTO>& dtos);
    void getByCampeonato(int campeonatoId, list<CorridaOutDTO>& dtos);
    void get(int id, CorridaOutDTO& dto);
    void remove(int id);
    void update(int id, const CorridaInDTO& dto);

    void assignCampeonato(int corridaId, int campeonatoId);
    void unassignCampeonato(int corridaId);
};
