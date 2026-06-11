#pragma once
#include "PilotoContainer.h"
#include "EquipaContainer.h"
#include "VeiculoContainer.h"

class RacingApp {
private:
    PilotoContainer  m_pilotos;
    EquipaContainer  m_equipas;
    VeiculoContainer m_veiculos;

public:
    RacingApp() = default;

    PilotoContainer&  getPilotoContainer();
    EquipaContainer&  getEquipaContainer();
    VeiculoContainer& getVeiculoContainer();
};
