#pragma once
#include "View.h"
#include "PilotoView.h"
#include "PilotoService.h"
#include "EquipaView.h"
#include "EquipaService.h"
#include "VeiculoView.h"
#include "VeiculoService.h"
#include "CorridaView.h"
#include "CorridaService.h"

class Controller {
private:
    View            m_view;
    PilotoView      m_pilotoView;
    PilotoService*  m_pilotoService;
    EquipaView      m_equipaView;
    EquipaService*  m_equipaService;
    VeiculoView     m_veiculoView;
    VeiculoService* m_veiculoService;
    CorridaView     m_corridaView;
    CorridaService* m_corridaService;

    void runPilotos();
    void runEquipas();
    void runVeiculos();
    void runCorridas();

public:
    Controller(PilotoService*  pilotoService,
               EquipaService*  equipaService,
               VeiculoService* veiculoService,
               CorridaService* corridaService);
    void run();
};
