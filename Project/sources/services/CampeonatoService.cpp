#include "CampeonatoService.h"
#include "CampeonatoMapper.h"
#include "RacingApp.h"
#include "DataConsistencyException.h"
#include <map>
#include <algorithm>
using namespace std;

CampeonatoService::CampeonatoService(IRacingRepository* repo) : m_repo(repo) {}

// ── Private helpers ───────────────────────────────────────────────────────────

string CampeonatoService::getPilotoNome(int pilotoId) {
    return m_repo->getModel()->getPilotoContainer().get(pilotoId)->getNome();
}
string CampeonatoService::getCorridaNome(int corridaId) {
    return m_repo->getModel()->getCorridaContainer().get(corridaId)->getNome();
}

// ── CRUD ──────────────────────────────────────────────────────────────────────

void CampeonatoService::add(const CampeonatoInDTO& dto) {
    m_repo->getModel()->getCampeonatoContainer().add(dto.nome, dto.ano);
    m_repo->persist();
}

void CampeonatoService::getAll(list<CampeonatoOutDTO>& dtos) {
    list<Campeonato*> campeonatos =
        m_repo->getModel()->getCampeonatoContainer().getAll();
    CampeonatoMapper::listModel2listDTO(campeonatos, dtos);
}

void CampeonatoService::get(int id, CampeonatoOutDTO& dto) {
    Campeonato* c = m_repo->getModel()->getCampeonatoContainer().get(id);
    CampeonatoMapper::model2DTO(c, dto);
}

void CampeonatoService::remove(int id) {
    RacingApp*           model = m_repo->getModel();
    CampeonatoContainer& c     = model->getCampeonatoContainer();

    // Refuse if campeonato still has corridas
    Campeonato* camp = c.get(id);
    if (!camp->getCorridaIds().empty())
        throw DataConsistencyException(
            "Campeonato id=" + to_string(id) + " still has corridas assigned");

    c.remove(id);
    m_repo->persist();
}

void CampeonatoService::update(int id, const CampeonatoInDTO& dto) {
    m_repo->getModel()->getCampeonatoContainer().update(id, dto.nome, dto.ano);
    m_repo->persist();
}

// ── Associations ──────────────────────────────────────────────────────────────

void CampeonatoService::addCorrida(int campeonatoId, int corridaId) {
    RacingApp* model = m_repo->getModel();
    // Validate corrida exists
    model->getCorridaContainer().get(corridaId);
    model->getCampeonatoContainer().addCorrida(campeonatoId, corridaId);
    // Also set campeonatoId on the corrida
    model->getCorridaContainer().assignCampeonato(corridaId, campeonatoId);
    m_repo->persist();
}

void CampeonatoService::removeCorrida(int campeonatoId, int corridaId) {
    RacingApp* model = m_repo->getModel();
    model->getCampeonatoContainer().removeCorrida(campeonatoId, corridaId);
    model->getCorridaContainer().unassignCampeonato(corridaId);
    m_repo->persist();
}

void CampeonatoService::addEquipa(int campeonatoId, int equipaId) {
    RacingApp* model = m_repo->getModel();
    // Validate equipa exists
    model->getEquipaContainer().get(equipaId);
    model->getCampeonatoContainer().addEquipa(campeonatoId, equipaId);
    m_repo->persist();
}

void CampeonatoService::removeEquipa(int campeonatoId, int equipaId) {
    m_repo->getModel()->getCampeonatoContainer().removeEquipa(campeonatoId, equipaId);
    m_repo->persist();
}

// ── Classificacao ─────────────────────────────────────────────────────────────

list<pair<string, int>> CampeonatoService::getClassificacao(int campeonatoId) {
    RacingApp*           model  = m_repo->getModel();
    Campeonato*          camp   = model->getCampeonatoContainer().get(campeonatoId);
    ParticipacaoContainer& parts = model->getParticipacaoContainer();

    // Accumulate points per piloto across all corridas in this campeonato
    map<int, int> pontosMap;
    for (int corridaId : camp->getCorridaIds()) {
        list<Participacao*> resultados = parts.getByCorrida(corridaId);
        for (auto* p : resultados)
            pontosMap[p->getPilotoId()] += p->getPontos();
    }

    // Build sorted list
    list<pair<string, int>> result;
    for (auto& [pilotoId, total] : pontosMap)
        result.emplace_back(getPilotoNome(pilotoId), total);

    result.sort([](const pair<string,int>& a, const pair<string,int>& b){
        return a.second > b.second;
    });
    return result;
}
