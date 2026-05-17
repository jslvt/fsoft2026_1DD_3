#pragma once
#include <vector>
#include <string>
#include "../model/Participacao.h"
#include "../store/ParticipacaoStore.h"
#include "PilotoController.h"
#include "CorridaController.h"

class ParticipacaoController {
public:
    ParticipacaoController(const std::string& ficheiro,
                           PilotoController&  pilotoCtrl,
                           CorridaController& corridaCtrl);

    bool registarParticipacao(int idPiloto, int idCorrida,
                              int posicao, float tempo);

    std::vector<Participacao> obterClassificacao(int idCorrida) const;

private:
    ParticipacaoStore          m_store;
    std::vector<Participacao>  m_participacoes;
    PilotoController&          m_pilotoCtrl;
    CorridaController&         m_corridaCtrl;

    void persistir();
    bool participacaoExiste(int idPiloto, int idCorrida) const;

    // F1-style points table (positions 1..10)
    static int pontosParaPosicao(int posicao);
};
