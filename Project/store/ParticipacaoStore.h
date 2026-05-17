#pragma once
#include <vector>
#include <string>
#include "../model/Participacao.h"

class ParticipacaoStore {
public:
    explicit ParticipacaoStore(const std::string& ficheiro);

    void                      guardar(const std::vector<Participacao>& participacoes);
    std::vector<Participacao> carregar();

private:
    std::string m_ficheiro;
};
