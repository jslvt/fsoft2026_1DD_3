#pragma once
#include <vector>
#include <string>
#include "../model/Piloto.h"

class PilotoStore {
public:
    explicit PilotoStore(const std::string& ficheiro);

    void                guardar(const std::vector<Piloto>& pilotos);
    std::vector<Piloto> carregar();

private:
    std::string m_ficheiro;
};
