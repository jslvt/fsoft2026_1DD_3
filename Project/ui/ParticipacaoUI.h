#pragma once
#include "../controller/ParticipacaoController.h"
#include "../controller/PilotoController.h"
#include "../controller/CorridaController.h"

class ParticipacaoUI {
public:
    ParticipacaoUI(ParticipacaoController& ctrl,
                   PilotoController&       pilotoCtrl,
                   CorridaController&      corridaCtrl);

    void registarParticipacao();
    void consultarClassificacao();

private:
    ParticipacaoController& m_ctrl;
    PilotoController&       m_pilotoCtrl;
    CorridaController&      m_corridaCtrl;

    // Returns 0 if the user cancels / list is empty
    int selecionarPiloto();
    int selecionarCorrida();
};
