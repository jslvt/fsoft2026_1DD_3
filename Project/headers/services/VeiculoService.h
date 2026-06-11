#pragma once
#include <list>
#include "IRacingRepository.h"
#include "VeiculoInDTO.h"
#include "VeiculoOutDTO.h"
using namespace std;

class VeiculoService {
private:
    IRacingRepository* m_repo;

public:
    explicit VeiculoService(IRacingRepository* repo);

    void add(const VeiculoInDTO& dto);
    void getAll(list<VeiculoOutDTO>& dtos);
    void getByEquipa(int equipaId, list<VeiculoOutDTO>& dtos);
    void get(int id, VeiculoOutDTO& dto);
    void remove(int id);
    void update(int id, const VeiculoInDTO& dto);

    // Assign / unassign equipa — validates equipa exists first
    void assignEquipa(int veiculoId, int equipaId);
    void unassignEquipa(int veiculoId);
};
