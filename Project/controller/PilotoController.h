#pragma once
#include <vector>
#include <string>
#include "../model/Piloto.h"
#include "../store/PilotoStore.h"

class PilotoController {
public:
    explicit PilotoController(const std::string& ficheiro);

    bool          criarPiloto(const std::string& nome,
                              const std::string& dataNasc,
                              const std::string& nLicenca);

    std::vector<Piloto> obterTodos() const;
    Piloto*             obterPorId(int id);

private:
    PilotoStore        m_store;
    std::vector<Piloto> m_pilotos;
    int                m_nextId;

    void   persistir();
    bool   licencaExiste(const std::string& nLicenca) const;
};
