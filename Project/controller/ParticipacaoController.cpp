#include "ParticipacaoController.h"
#include <algorithm>
#include <iostream>

ParticipacaoController::ParticipacaoController(const std::string& ficheiro,
                                               PilotoController&  pilotoCtrl,
                                               CorridaController& corridaCtrl)
    : m_store(ficheiro),
      m_pilotoCtrl(pilotoCtrl),
      m_corridaCtrl(corridaCtrl)
{
    m_participacoes = m_store.carregar();
}

bool ParticipacaoController::registarParticipacao(int idPiloto, int idCorrida,
                                                   int posicao, float tempo)
{
    if (m_pilotoCtrl.obterPorId(idPiloto) == nullptr) {
        std::cerr << "[ParticipacaoController] Piloto não encontrado: "
                  << idPiloto << "\n";
        return false;
    }
    if (m_corridaCtrl.obterPorId(idCorrida) == nullptr) {
        std::cerr << "[ParticipacaoController] Corrida não encontrada: "
                  << idCorrida << "\n";
        return false;
    }
    if (posicao < 1 || tempo <= 0.0f) {
        std::cerr << "[ParticipacaoController] Posição ou tempo inválidos.\n";
        return false;
    }
    if (participacaoExiste(idPiloto, idCorrida)) {
        std::cerr << "[ParticipacaoController] Participação já registada "
                     "para este piloto nesta corrida.\n";
        return false;
    }

    int pontos = pontosParaPosicao(posicao);
    m_participacoes.emplace_back(idPiloto, idCorrida, posicao, tempo, pontos);
    persistir();
    return true;
}

std::vector<Participacao>
ParticipacaoController::obterClassificacao(int idCorrida) const
{
    std::vector<Participacao> resultado;
    for (const auto& p : m_participacoes)
        if (p.getIdCorrida() == idCorrida)
            resultado.push_back(p);

    std::sort(resultado.begin(), resultado.end(),
        [](const Participacao& a, const Participacao& b){
            return a.getPosicao() < b.getPosicao();
        });
    return resultado;
}

// ── private ────────────────────────────────────────────────────────────────

void ParticipacaoController::persistir() {
    m_store.guardar(m_participacoes);
}

bool ParticipacaoController::participacaoExiste(int idPiloto,
                                                 int idCorrida) const
{
    return std::any_of(m_participacoes.begin(), m_participacoes.end(),
        [&](const Participacao& p){
            return p.getIdPiloto() == idPiloto &&
                   p.getIdCorrida() == idCorrida;
        });
}

int ParticipacaoController::pontosParaPosicao(int posicao) {
    // Standard F1 points system
    static const int tabela[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    if (posicao >= 1 && posicao <= 10)
        return tabela[posicao - 1];
    return 0;
}
