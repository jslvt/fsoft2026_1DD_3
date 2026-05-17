#pragma once
#include "../controller/VeiculoController.h"

class VeiculoUI {
public:
    explicit VeiculoUI(VeiculoController& ctrl);

    void criarVeiculo();
    void listarVeiculos();

private:
    VeiculoController& m_ctrl;
};
