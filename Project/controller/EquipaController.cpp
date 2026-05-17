#include "EquipaController.h"
#include <iostream>

EquipaController::EquipaController(const std::string& ficheiro)
    : m_store(ficheiro), m_nextId(1)
{
    m_equipas = m_store.carregar();
    for (const auto& e : m_equipas)
        if (e.getId() >= m_nextId)
            m_nextId = e.getId() + 1;
}

bool EquipaController::criarEquipa(const std::string& nome,
                                    const std::string& pais)
{
    if (nome.empty() || pais.empty()) {
        std::cerr << "[EquipaController] Dados inválidos: campos vazios.\n";
        return false;
    }
    m_equipas.emplace_back(m_nextId++, nome, pais);
    persistir();
    return true;
}

std::vector<Equipa> EquipaController::obterTodos() const {
    return m_equipas;
}

Equipa* EquipaController::obterPorId(int id) {
    for (auto& e : m_equipas)
        if (e.getId() == id)
            return &e;
    return nullptr;
}

void EquipaController::persistir() {
    m_store.guardar(m_equipas);
}
