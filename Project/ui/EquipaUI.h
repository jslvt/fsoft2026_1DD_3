#pragma once
#include "../controller/EquipaController.h"

class EquipaUI {
public:
    explicit EquipaUI(EquipaController& ctrl);

    void criarEquipa();
    void listarEquipas();

private:
    EquipaController& m_ctrl;
};
