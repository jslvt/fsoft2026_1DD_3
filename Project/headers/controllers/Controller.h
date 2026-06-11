#pragma once
#include "View.h"
#include "PilotoView.h"
#include "PilotoService.h"
// EquipaService, VeiculoService, etc. — added in later iterations

class Controller {
private:
    View         m_view;
    PilotoView   m_pilotoView;
    PilotoService* m_pilotoService;

    void runPilotos();

public:
    explicit Controller(PilotoService* pilotoService);
    void run();
};
