#pragma once
#include "PilotoContainer.h"
#include "EquipaContainer.h"
#include "VeiculoContainer.h"
#include "CorridaContainer.h"
#include "ParticipacaoContainer.h"
#include "CampeonatoContainer.h"

class RacingApp {
private:
    PilotoContainer       m_pilotos;
    EquipaContainer       m_equipas;
    VeiculoContainer      m_veiculos;
    CorridaContainer      m_corridas;
    ParticipacaoContainer m_participacoes;
    CampeonatoContainer   m_campeonatos;

public:
    RacingApp() = default;

    PilotoContainer&       getPilotoContainer();
    EquipaContainer&       getEquipaContainer();
    VeiculoContainer&      getVeiculoContainer();
    CorridaContainer&      getCorridaContainer();
    ParticipacaoContainer& getParticipacaoContainer();
    CampeonatoContainer&   getCampeonatoContainer();
};
