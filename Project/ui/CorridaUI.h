#pragma once
#include "../controller/CorridaController.h"

class CorridaUI {
public:
    explicit CorridaUI(CorridaController& ctrl);

    void criarCorrida();
    void listarCorridas();

private:
    CorridaController& m_ctrl;
};
