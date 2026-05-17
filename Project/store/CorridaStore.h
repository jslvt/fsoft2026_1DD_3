#pragma once
#include <vector>
#include <string>
#include "../model/Corrida.h"

class CorridaStore {
public:
    explicit CorridaStore(const std::string& ficheiro);

    void                 guardar(const std::vector<Corrida>& corridas);
    std::vector<Corrida> carregar();

private:
    std::string m_ficheiro;
};
