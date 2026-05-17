#pragma once
#include "../controller/PilotoController.h"

class PilotoUI {
public:
    explicit PilotoUI(PilotoController& ctrl);

    void criarPiloto();
    void listarPilotos();

private:
    PilotoController& m_ctrl;
};
