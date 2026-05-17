#pragma once
#include <vector>
#include <string>
#include "../model/Equipa.h"
#include "../store/EquipaStore.h"

class EquipaController {
public:
    explicit EquipaController(const std::string& ficheiro);

    bool criarEquipa(const std::string& nome, const std::string& pais);

    std::vector<Equipa> obterTodos() const;
    Equipa*             obterPorId(int id);

private:
    EquipaStore         m_store;
    std::vector<Equipa> m_equipas;
    int                 m_nextId;

    void persistir();
};
