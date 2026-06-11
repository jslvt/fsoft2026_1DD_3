#pragma once
#include "PilotoContainer.h"
#include "EquipaContainer.h"

class RacingApp {
private:
    PilotoContainer m_pilotos;
    EquipaContainer m_equipas;

public:
    RacingApp() = default;

    PilotoContainer& getPilotoContainer();
    EquipaContainer& getEquipaContainer();
};
