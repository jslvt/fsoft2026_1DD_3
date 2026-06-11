#pragma once
#include <list>
#include "PilotoInDTO.h"
#include "PilotoOutDTO.h"
using namespace std;

class PilotoView {
public:
    PilotoView() = default;

    int menuPilotos();

    // Collect input from user → returns PilotoInDTO
    PilotoInDTO getPiloto();

    // Read just an id from user
    int getId();

    // Display one or many pilotos
    void printPiloto(const PilotoOutDTO& dto);
    void printPilotos(list<PilotoOutDTO>& dtos);
};