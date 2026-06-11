#pragma once
#include <list>
#include "Corrida.h"
#include "CorridaOutDTO.h"
using namespace std;

class CorridaMapper {
public:
    static void model2DTO(Corrida* obj, CorridaOutDTO& dto);
    static void listModel2listDTO(list<Corrida*>& objs, list<CorridaOutDTO>& dtos);
};
