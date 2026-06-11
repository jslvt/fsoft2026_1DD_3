#pragma once
#include <list>
#include "VeiculoInDTO.h"
#include "VeiculoOutDTO.h"
using namespace std;

class VeiculoView {
public:
    VeiculoView() = default;

    int menuVeiculos();

    VeiculoInDTO getVeiculo();
    int          getId();
    int          getEquipaId();

    void printVeiculo(const VeiculoOutDTO& dto);
    void printVeiculos(list<VeiculoOutDTO>& dtos);
};
