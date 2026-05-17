#pragma once
#include <vector>
#include <string>
#include "../model/Corrida.h"
#include "../store/CorridaStore.h"

class CorridaController {
public:
    explicit CorridaController(const std::string& ficheiro);

    bool criarCorrida(const std::string& nome,
                      const std::string& circuito,
                      const std::string& data);

    std::vector<Corrida> obterTodos() const;
    Corrida*             obterPorId(int id);

private:
    CorridaStore          m_store;
    std::vector<Corrida>  m_corridas;
    int                   m_nextId;

    void persistir();
};
