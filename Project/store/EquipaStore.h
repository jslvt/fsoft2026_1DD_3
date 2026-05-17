#pragma once
#include <vector>
#include <string>
#include "../model/Equipa.h"

class EquipaStore {
public:
    explicit EquipaStore(const std::string& ficheiro);

    void                guardar(const std::vector<Equipa>& equipas);
    std::vector<Equipa> carregar();

private:
    std::string m_ficheiro;
};
