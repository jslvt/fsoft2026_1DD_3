#include "VeiculoController.h"
#include <algorithm>
#include <iostream>

VeiculoController::VeiculoController(const std::string& ficheiro)
    : m_store(ficheiro), m_nextId(1)
{
    m_veiculos = m_store.carregar();
    for (const auto& v : m_veiculos)
        if (v.getId() >= m_nextId)
            m_nextId = v.getId() + 1;
}

bool VeiculoController::criarVeiculo(const std::string& modelo,
                                      const std::string& matricula,
                                      int ano)
{
    if (modelo.empty() || matricula.empty() || ano < 1900 || ano > 2100) {
        std::cerr << "[VeiculoController] Dados invalidos.\n";
        return false;
    }
    if (matriculaExiste(matricula)) {
        std::cerr << "[VeiculoController] Matricula ja existe: " << matricula << "\n";
        return false;
    }
    m_veiculos.emplace_back(m_nextId++, modelo, matricula, ano);
    persistir();
    return true;
}

std::vector<Veiculo> VeiculoController::obterTodos() const {
    return m_veiculos;
}

void VeiculoController::persistir() {
    m_store.guardar(m_veiculos);
}

bool VeiculoController::matriculaExiste(const std::string& matricula) const {
    return std::any_of(m_veiculos.begin(), m_veiculos.end(),
        [&](const Veiculo& v){ return v.getMatricula() == matricula; });
}
