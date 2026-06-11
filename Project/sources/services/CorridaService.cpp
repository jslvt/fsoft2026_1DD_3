#include "CorridaService.h"
#include "CorridaMapper.h"
#include "RacingApp.h"
#include "DataConsistencyException.h"

CorridaService::CorridaService(IRacingRepository* repo) : m_repo(repo) {}

void CorridaService::add(const CorridaInDTO& dto) {
    RacingApp*        model = m_repo->getModel();
    CorridaContainer& c     = model->getCorridaContainer();
    c.add(dto.nome, dto.circuito, dto.data, dto.tipo);
    m_repo->persist();
}

void CorridaService::getAll(list<CorridaOutDTO>& dtos) {
    RacingApp*        model   = m_repo->getModel();
    CorridaContainer& c       = model->getCorridaContainer();
    list<Corrida*>    corridas = c.getAll();
    CorridaMapper::listModel2listDTO(corridas, dtos);
}

void CorridaService::getByCampeonato(int campeonatoId, list<CorridaOutDTO>& dtos) {
    RacingApp*        model   = m_repo->getModel();
    CorridaContainer& c       = model->getCorridaContainer();
    list<Corrida*>    corridas = c.getByCampeonato(campeonatoId);
    CorridaMapper::listModel2listDTO(corridas, dtos);
}

void CorridaService::get(int id, CorridaOutDTO& dto) {
    RacingApp*        model = m_repo->getModel();
    CorridaContainer& c     = model->getCorridaContainer();
    Corrida*          cr    = c.get(id);
    CorridaMapper::model2DTO(cr, dto);
}

void CorridaService::remove(int id) {
    RacingApp*        model = m_repo->getModel();
    CorridaContainer& c     = model->getCorridaContainer();
    // Future: check ParticipacaoContainer for references
    c.remove(id);
    m_repo->persist();
}

void CorridaService::update(int id, const CorridaInDTO& dto) {
    RacingApp*        model = m_repo->getModel();
    CorridaContainer& c     = model->getCorridaContainer();
    c.update(id, dto.nome, dto.circuito, dto.data, dto.tipo);
    m_repo->persist();
}

void CorridaService::assignCampeonato(int corridaId, int campeonatoId) {
    RacingApp* model = m_repo->getModel();
    // Will validate campeonato exists once CampeonatoContainer is added
    model->getCorridaContainer().assignCampeonato(corridaId, campeonatoId);
    m_repo->persist();
}

void CorridaService::unassignCampeonato(int corridaId) {
    m_repo->getModel()->getCorridaContainer().unassignCampeonato(corridaId);
    m_repo->persist();
}
