#pragma once
#include <list>
#include "IRacingRepository.h"
#include "EquipaInDTO.h"
#include "EquipaOutDTO.h"
using namespace std;

class EquipaService {
private:
    IRacingRepository* m_repo;

public:
    explicit EquipaService(IRacingRepository* repo);

    void add(const EquipaInDTO& dto);
    void getAll(list<EquipaOutDTO>& dtos);
    void get(int id, EquipaOutDTO& dto);
    void remove(int id);
    void update(int id, const EquipaInDTO& dto);

    // Associate / disassociate a piloto — validates piloto exists first
    void addPiloto(int equipaId, int pilotoId);
    void removePiloto(int equipaId, int pilotoId);
};
