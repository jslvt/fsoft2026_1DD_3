#include "CorridaController.h"
#include <iostream>

CorridaController::CorridaController(const std::string& ficheiro)
    : m_store(ficheiro), m_nextId(1)
{
    m_corridas = m_store.carregar();
    for (const auto& c : m_corridas)
        if (c.getId() >= m_nextId)
            m_nextId = c.getId() + 1;
}

bool CorridaController::criarCorrida(const std::string& nome,
                                      const std::string& circuito,
                                      const std::string& data)
{
    if (nome.empty() || circuito.empty() || data.empty()) {
        std::cerr << "[CorridaController] Dados invalidos: campos vazios.\n";
        return false;
    }
    m_corridas.emplace_back(m_nextId++, nome, circuito, data);
    persistir();
    return true;
}

std::vector<Corrida> CorridaController::obterTodos() const {
    return m_corridas;
}

Corrida* CorridaController::obterPorId(int id) {
    for (auto& c : m_corridas)
        if (c.getId() == id)
            return &c;
    return nullptr;
}

void CorridaController::persistir() {
    m_store.guardar(m_corridas);
}
