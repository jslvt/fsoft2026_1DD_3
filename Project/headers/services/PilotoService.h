#pragma once
#include <list>
#include "IRacingRepository.h"
#include "PilotoInDTO.h"
#include "PilotoOutDTO.h"
using namespace std;

class PilotoService {
private:
    IRacingRepository* m_repo;

public:
    explicit PilotoService(IRacingRepository* repo);

    void add(const PilotoInDTO& dto);
    void getAll(list<PilotoOutDTO>& dtos);
    void get(int id, PilotoOutDTO& dto);

    // Throws DataConsistencyException if piloto has participacoes
    // or still belongs to an equipa
    void remove(int id);

    void update(int id, const PilotoInDTO& dto);
};