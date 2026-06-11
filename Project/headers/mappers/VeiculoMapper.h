#pragma once
#include <list>
#include "Veiculo.h"
#include "VeiculoOutDTO.h"
using namespace std;

class VeiculoMapper {
public:
    static void model2DTO(Veiculo* obj, VeiculoOutDTO& dto);
    static void listModel2listDTO(list<Veiculo*>& objs, list<VeiculoOutDTO>& dtos);
};
