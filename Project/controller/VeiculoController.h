#pragma once
#include <vector>
#include <string>
#include "../model/Veiculo.h"
#include "../store/VeiculoStore.h"

class VeiculoController {
public:
    explicit VeiculoController(const std::string& ficheiro);

    bool criarVeiculo(const std::string& modelo,
                      const std::string& matricula,
                      int ano);

    std::vector<Veiculo> obterTodos() const;

private:
    VeiculoStore          m_store;
    std::vector<Veiculo>  m_veiculos;
    int                   m_nextId;

    void persistir();
    bool matriculaExiste(const std::string& matricula) const;
};
