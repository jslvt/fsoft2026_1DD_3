#include "ParticipacaoContainer.h"
#include "NoDataException.h"
#include "DuplicatedDataException.h"
#include <algorithm>

// ── F1 points ─────────────────────────────────────────────────────────────────

int ParticipacaoContainer::calcPontos(int posicao) {
    static const int tabela[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    if (posicao >= 1 && posicao <= 10)
        return tabela[posicao - 1];
    return 0;
}

// ── add ───────────────────────────────────────────────────────────────────────

void ParticipacaoContainer::add(int pilotoId, int corridaId,
                                 int posicao, float tempo, bool isCampeonato) {
    for (auto& p : m_participacoes)
        if (p.getPilotoId() == pilotoId && p.getCorridaId() == corridaId)
            throw DuplicatedDataException(
                "Piloto id=" + to_string(pilotoId) +
                " already registered in corrida id=" + to_string(corridaId));

    int pontos = isCampeonato ? calcPontos(posicao) : 0;
    m_participacoes.emplace_back(pilotoId, corridaId, posicao, tempo, pontos);
}

// ── get ───────────────────────────────────────────────────────────────────────

Participacao* ParticipacaoContainer::get(int pilotoId, int corridaId) {
    for (auto& p : m_participacoes)
        if (p.getPilotoId() == pilotoId && p.getCorridaId() == corridaId)
            return &p;
    throw NoDataException(
        "Participacao piloto=" + to_string(pilotoId) +
        " corrida=" + to_string(corridaId) + " not found");
}

list<Participacao*> ParticipacaoContainer::getByCorrida(int corridaId) {
    list<Participacao*> result;
    for (auto& p : m_participacoes)
        if (p.getCorridaId() == corridaId)
            result.push_back(&p);
    // Sort by posicao ascending
    result.sort([](Participacao* a, Participacao* b){
        return a->getPosicao() < b->getPosicao();
    });
    return result;
}

list<Participacao*> ParticipacaoContainer::getByPiloto(int pilotoId) {
    list<Participacao*> result;
    for (auto& p : m_participacoes)
        if (p.getPilotoId() == pilotoId)
            result.push_back(&p);
    return result;
}

list<Participacao*> ParticipacaoContainer::getAll() {
    list<Participacao*> result;
    for (auto& p : m_participacoes)
        result.push_back(&p);
    return result;
}

// ── checks ────────────────────────────────────────────────────────────────────

bool ParticipacaoContainer::hasPiloto(int pilotoId) const {
    for (const auto& p : m_participacoes)
        if (p.getPilotoId() == pilotoId) return true;
    return false;
}

bool ParticipacaoContainer::hasCorrida(int corridaId) const {
    for (const auto& p : m_participacoes)
        if (p.getCorridaId() == corridaId) return true;
    return false;
}

// ── remove ────────────────────────────────────────────────────────────────────

void ParticipacaoContainer::remove(int pilotoId, int corridaId) {
    for (auto it = m_participacoes.begin(); it != m_participacoes.end(); ++it) {
        if (it->getPilotoId() == pilotoId && it->getCorridaId() == corridaId) {
            m_participacoes.erase(it);
            return;
        }
    }
    throw NoDataException(
        "Participacao piloto=" + to_string(pilotoId) +
        " corrida=" + to_string(corridaId) + " not found");
}

// ── update ────────────────────────────────────────────────────────────────────

void ParticipacaoContainer::update(int pilotoId, int corridaId,
                                    int posicao, float tempo, bool isCampeonato) {
    Participacao* p = get(pilotoId, corridaId);
    p->setPosicao(posicao);
    p->setTempo(tempo);
    p->setPontos(isCampeonato ? calcPontos(posicao) : 0);
}

// ── restore ───────────────────────────────────────────────────────────────────

void ParticipacaoContainer::restore(int pilotoId, int corridaId,
                                     int posicao, float tempo, int pontos) {
    m_participacoes.emplace_back(pilotoId, corridaId, posicao, tempo, pontos);
}
