#pragma once
#include "PilotoContainer.h"
using namespace std;

// Root model object — equivalent to School in the teacher's project.
// Holds all containers. The repository owns one instance of this.
class RacingApp {
private:
    PilotoContainer m_pilotos;
    // EquipaContainer, VeiculoContainer, CorridaContainer,
    // ParticipacaoContainer, CampeonatoContainer — added in later iterations

public:
    RacingApp() = default;

    PilotoContainer& getPilotoContainer();
};
