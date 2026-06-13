#include "ParticipacaoService.h"
#include "ParticipacaoMapper.h"
#include "RacingApp.h"
#include "TipoCorrida.h"
#include <algorithm>
#include <map>
using namespace std;

ParticipacaoService::ParticipacaoService(IRacingRepository* repo) : m_repo(repo) {}

// ── Private helpers ───────────────────────────────────────────────────────────

string ParticipacaoService::getPilotoNome(int pilotoId) {
    return m_repo->getModel()->getPilotoContainer().get(pilotoId)->getNome();
}

string ParticipacaoService::getCorridaNome(int corridaId) {
    return m_repo->getModel()->getCorridaContainer().get(corridaId)->getNome();
}

bool ParticipacaoService::isCampeonato(int corridaId) {
    return m_repo->getModel()->getCorridaContainer().get(corridaId)->getTipo()
           == TipoCorrida::CAMPEONATO;
}

// ── add ───────────────────────────────────────────────────────────────────────

void ParticipacaoService::add(const ParticipacaoInDTO& dto) {
    RacingApp* model = m_repo->getModel();

    // Validate piloto exists — throws NoDataException if not
    model->getPilotoContainer().get(dto.pilotoId);

    // Validate corrida exists — throws NoDataException if not
    model->getCorridaContainer().get(dto.corridaId);

    bool campeonato = isCampeonato(dto.corridaId);
    model->getParticipacaoContainer().add(
        dto.pilotoId, dto.corridaId, dto.posicao, dto.tempo, campeonato);

    m_repo->persist();
}

// ── queries ───────────────────────────────────────────────────────────────────

void ParticipacaoService::getByCorrida(int corridaId, list<ParticipacaoOutDTO>& dtos) {
    RacingApp* model = m_repo->getModel();
    string corridaNome = getCorridaNome(corridaId);
    list<Participacao*> parts = model->getParticipacaoContainer().getByCorrida(corridaId);
    for (auto* p : parts) {
        ParticipacaoOutDTO dto;
        string pilotoNome = getPilotoNome(p->getPilotoId());
        ParticipacaoMapper::model2DTO(p, dto, pilotoNome, corridaNome);
        dtos.push_back(dto);
    }
}

void ParticipacaoService::getByPiloto(int pilotoId, list<ParticipacaoOutDTO>& dtos) {
    RacingApp* model = m_repo->getModel();
    string pilotoNome = getPilotoNome(pilotoId);
    list<Participacao*> parts = model->getParticipacaoContainer().getByPiloto(pilotoId);
    for (auto* p : parts) {
        ParticipacaoOutDTO dto;
        string corridaNome = getCorridaNome(p->getCorridaId());
        ParticipacaoMapper::model2DTO(p, dto, pilotoNome, corridaNome);
        dtos.push_back(dto);
    }
}

list<pair<string, int>> ParticipacaoService::getClassificacaoGeral() {
    RacingApp* model = m_repo->getModel();
    list<Participacao*> all = model->getParticipacaoContainer().getAll();

    // Accumulate points per piloto
    map<int, int> pontosMap;
    for (auto* p : all)
        if (isCampeonato(p->getCorridaId()))
            pontosMap[p->getPilotoId()] += p->getPontos();

    // Build sorted list
    list<pair<string, int>> result;
    for (auto& [pilotoId, total] : pontosMap)
        result.emplace_back(getPilotoNome(pilotoId), total);

    result.sort([](const pair<string,int>& a, const pair<string,int>& b){
        return a.second > b.second;
    });
    return result;
}

// ── remove / update ───────────────────────────────────────────────────────────

void ParticipacaoService::remove(int pilotoId, int corridaId) {
    m_repo->getModel()->getParticipacaoContainer().remove(pilotoId, corridaId);
    m_repo->persist();
}

void ParticipacaoService::update(const ParticipacaoInDTO& dto) {
    bool campeonato = isCampeonato(dto.corridaId);
    m_repo->getModel()->getParticipacaoContainer().update(
        dto.pilotoId, dto.corridaId, dto.posicao, dto.tempo, campeonato);
    m_repo->persist();
}
