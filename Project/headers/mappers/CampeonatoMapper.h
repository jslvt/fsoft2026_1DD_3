#pragma once
#include <list>
#include "Campeonato.h"
#include "CampeonatoOutDTO.h"
using namespace std;

class CampeonatoMapper {
public:
    static void model2DTO(Campeonato* obj, CampeonatoOutDTO& dto);
    static void listModel2listDTO(list<Campeonato*>& objs, list<CampeonatoOutDTO>& dtos);
};
