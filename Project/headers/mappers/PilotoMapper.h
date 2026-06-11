#pragma once
#include <list>
#include "Piloto.h"
#include "PilotoOutDTO.h"
using namespace std;

class PilotoMapper {
public:
    // Convert one model object to an output DTO
    static void model2DTO(Piloto* obj, PilotoOutDTO& dto);

    // Convert a list of model pointers to a list of output DTOs
    static void listModel2listDTO(list<Piloto*>& objs, list<PilotoOutDTO>& dtos);
};
