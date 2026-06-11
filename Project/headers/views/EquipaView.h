#pragma once
#include <list>
#include "EquipaInDTO.h"
#include "EquipaOutDTO.h"
using namespace std;

class EquipaView {
public:
    EquipaView() = default;

    int menuEquipas();

    EquipaInDTO getEquipa();
    int         getId();
    int         getPilotoId();

    void printEquipa(const EquipaOutDTO& dto);
    void printEquipas(list<EquipaOutDTO>& dtos);
};
