#include "PilotoService.h"
#include "PilotoMapper.h"
#include "RacingApp.h"
#include "DataConsistencyException.h"

PilotoService::PilotoService(IRacingRepository* repo) : m_repo(repo) {}

void PilotoService::add(const PilotoInDTO& dto) {
    RacingApp*       model     = m_repo->getModel();
    PilotoContainer& container = model->getPilotoContainer();
    container.add(dto.nome, dto.dataNasc, dto.nLicenca);
    m_repo->persist();
}

void PilotoService::getAll(list<PilotoOutDTO>& dtos) {
    RacingApp*       model   = m_repo->getModel();
    PilotoContainer& c       = model->getPilotoContainer();
    list<Piloto*>    pilotos = c.getAll();
    PilotoMapper::listModel2listDTO(pilotos, dtos);
}

void PilotoService::get(int id, PilotoOutDTO& dto) {
    RacingApp*       model = m_repo->getModel();
    PilotoContainer& c     = model->getPilotoContainer();
    Piloto*          p     = c.get(id);
    PilotoMapper::model2DTO(p, dto);
}

void PilotoService::remove(int id) {
    RacingApp* model = m_repo->getModel();

    // Refuse if piloto has participacoes
    if (model->getParticipacaoContainer().hasPiloto(id))
        throw DataConsistencyException(
            "Piloto id=" + to_string(id) +
            " has participacoes registered and cannot be removed");

    // Refuse if piloto belongs to an equipa
    Equipa* equipa = model->getEquipaContainer().findEquipaByPiloto(id);
    if (equipa != nullptr)
        throw DataConsistencyException(
            "Piloto id=" + to_string(id) +
            " belongs to equipa '" + equipa->getNome() +
            "' — remove from equipa first");

    model->getPilotoContainer().remove(id);
    m_repo->persist();
}

void PilotoService::update(int id, const PilotoInDTO& dto) {
    RacingApp*       model = m_repo->getModel();
    PilotoContainer& c     = model->getPilotoContainer();
    c.update(id, dto.nome, dto.dataNasc, dto.nLicenca);
    m_repo->persist();
}