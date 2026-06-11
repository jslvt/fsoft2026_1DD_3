#pragma once
#include <list>
#include "Equipa.h"
#include "EquipaOutDTO.h"
using namespace std;

class EquipaMapper {
public:
    static void model2DTO(Equipa* obj, EquipaOutDTO& dto);
    static void listModel2listDTO(list<Equipa*>& objs, list<EquipaOutDTO>& dtos);
};
