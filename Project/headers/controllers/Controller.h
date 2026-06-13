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
#include "ParticipacaoView.h"
#include "ParticipacaoService.h"
#include "CampeonatoView.h"
#include "CampeonatoService.h"

class Controller {
private:
    View                 m_view;
    PilotoView           m_pilotoView;
    PilotoService*       m_pilotoService;
    EquipaView           m_equipaView;
    EquipaService*       m_equipaService;
    VeiculoView          m_veiculoView;
    VeiculoService*      m_veiculoService;
    CorridaView          m_corridaView;
    CorridaService*      m_corridaService;
    ParticipacaoView     m_participacaoView;
    ParticipacaoService* m_participacaoService;
    CampeonatoView       m_campeonatoView;
    CampeonatoService*   m_campeonatoService;

    void runPilotos();
    void runEquipas();
    void runVeiculos();
    void runCorridas();
    void runParticipacoes();
    void runCampeonatos();

public:
    Controller(PilotoService*       pilotoService,
               EquipaService*       equipaService,
               VeiculoService*      veiculoService,
               CorridaService*      corridaService,
               ParticipacaoService* participacaoService,
               CampeonatoService*   campeonatoService);
    void run();
};
