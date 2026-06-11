#pragma once
#include "View.h"
#include "PilotoView.h"
#include "PilotoService.h"
#include "EquipaView.h"
#include "EquipaService.h"

class Controller {
private:
    View          m_view;
    PilotoView    m_pilotoView;
    PilotoService* m_pilotoService;
    EquipaView    m_equipaView;
    EquipaService* m_equipaService;

    void runPilotos();
    void runEquipas();

public:
    Controller(PilotoService* pilotoService,
               EquipaService* equipaService);
    void run();
};
