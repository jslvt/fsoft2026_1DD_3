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

    // UC1 — Criar Piloto
    void add(const PilotoInDTO& dto);

    // UC2 — Listar Pilotos
    void getAll(list<PilotoOutDTO>& dtos);

    // Get single piloto by id
    void get(int id, PilotoOutDTO& dto);

    // Remove piloto — throws DataConsistencyException if has participacoes
    void remove(int id);

    // Update piloto fields
    void update(int id, const PilotoInDTO& dto);
};