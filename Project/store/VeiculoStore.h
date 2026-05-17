#pragma once
#include <vector>
#include <string>
#include "../model/Veiculo.h"

class VeiculoStore {
public:
    explicit VeiculoStore(const std::string& ficheiro);

    void                 guardar(const std::vector<Veiculo>& veiculos);
    std::vector<Veiculo> carregar();

private:
    std::string m_ficheiro;
};
