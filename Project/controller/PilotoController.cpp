#include "PilotoController.h"
#include <algorithm>
#include <iostream>

PilotoController::PilotoController(const std::string& ficheiro)
    : m_store(ficheiro), m_nextId(1)
{
    m_pilotos = m_store.carregar();
    for (const auto& p : m_pilotos)
        if (p.getId() >= m_nextId)
            m_nextId = p.getId() + 1;
}

bool PilotoController::criarPiloto(const std::string& nome,
                                    const std::string& dataNasc,
                                    const std::string& nLicenca)
{
    if (nome.empty() || dataNasc.empty() || nLicenca.empty()) {
        std::cerr << "[PilotoController] Dados invalidos: campos vazios.\n";
        return false;
    }
    if (licencaExiste(nLicenca)) {
        std::cerr << "[PilotoController] Numero de licenca ja existe: "
                  << nLicenca << "\n";
        return false;
    }
    m_pilotos.emplace_back(m_nextId++, nome, dataNasc, nLicenca);
    persistir();
    return true;
}

std::vector<Piloto> PilotoController::obterTodos() const {
    return m_pilotos;
}

Piloto* PilotoController::obterPorId(int id) {
    for (auto& p : m_pilotos)
        if (p.getId() == id)
            return &p;
    return nullptr;
}

// ── private ────────────────────────────────────────────────────────────────

void PilotoController::persistir() {
    m_store.guardar(m_pilotos);
}

bool PilotoController::licencaExiste(const std::string& nLicenca) const {
    return std::any_of(m_pilotos.begin(), m_pilotos.end(),
        [&](const Piloto& p){ return p.getNLicenca() == nLicenca; });
}
