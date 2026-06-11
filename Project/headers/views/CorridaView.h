#pragma once
#include <list>
#include "CorridaInDTO.h"
#include "CorridaOutDTO.h"
using namespace std;

class CorridaView {
public:
    CorridaView() = default;

    int menuCorridas();

    CorridaInDTO getCorrida();
    int          getId();
    int          getCampeonatoId();

    void printCorrida(const CorridaOutDTO& dto);
    void printCorridas(list<CorridaOutDTO>& dtos);
};
