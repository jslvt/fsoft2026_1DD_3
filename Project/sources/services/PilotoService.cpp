#include "PilotoService.h"
#include "PilotoMapper.h"
#include "RacingApp.h"

PilotoService::PilotoService(IRacingRepository* repo)
    : m_repo(repo) {}

void PilotoService::add(const PilotoInDTO& dto) {
    RacingApp*       model     = m_repo->getModel();
    PilotoContainer& container = model->getPilotoContainer();

    // Container throws DuplicatedDataException if licence exists
    // Piloto constructor throws InvalidDataException if data is bad
    container.add(dto.nome, dto.dataNasc, dto.nLicenca);

    // Persist immediately after every change
    m_repo->persist();
}

void PilotoService::getAll(list<PilotoOutDTO>& dtos) {
    RacingApp*       model     = m_repo->getModel();
    PilotoContainer& container = model->getPilotoContainer();
    list<Piloto*>    pilotos   = container.getAll();
    PilotoMapper::listModel2listDTO(pilotos, dtos);
}

void PilotoService::get(int id, PilotoOutDTO& dto) {
    RacingApp*       model     = m_repo->getModel();
    PilotoContainer& container = model->getPilotoContainer();
    Piloto*          piloto    = container.get(id);  // throws NoDataException
    PilotoMapper::model2DTO(piloto, dto);
}

void PilotoService::remove(int id) {
    RacingApp*       model     = m_repo->getModel();
    PilotoContainer& container = model->getPilotoContainer();

    // Future: check ParticipacaoContainer for references before removing
    // and throw DataConsistencyException if found
    container.remove(id);  // throws NoDataException if not found
    m_repo->persist();
}

void PilotoService::update(int id, const PilotoInDTO& dto) {
    RacingApp*       model     = m_repo->getModel();
    PilotoContainer& container = model->getPilotoContainer();
    container.update(id, dto.nome, dto.dataNasc, dto.nLicenca);
    m_repo->persist();
}