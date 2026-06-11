#include "EquipaService.h"
#include "EquipaMapper.h"
#include "RacingApp.h"
#include "DataConsistencyException.h"

EquipaService::EquipaService(IRacingRepository* repo) : m_repo(repo) {}

void EquipaService::add(const EquipaInDTO& dto) {
    RacingApp*       model = m_repo->getModel();
    EquipaContainer& c     = model->getEquipaContainer();
    c.add(dto.nome, dto.pais);
    m_repo->persist();
}

void EquipaService::getAll(list<EquipaOutDTO>& dtos) {
    RacingApp*       model  = m_repo->getModel();
    EquipaContainer& c      = model->getEquipaContainer();
    list<Equipa*>    equipas = c.getAll();
    EquipaMapper::listModel2listDTO(equipas, dtos);
}

void EquipaService::get(int id, EquipaOutDTO& dto) {
    RacingApp*       model = m_repo->getModel();
    EquipaContainer& c     = model->getEquipaContainer();
    Equipa*          e     = c.get(id);   // throws NoDataException
    EquipaMapper::model2DTO(e, dto);
}

void EquipaService::remove(int id) {
    RacingApp*       model = m_repo->getModel();
    EquipaContainer& c     = model->getEquipaContainer();

    // Refuse if equipa still has pilots
    Equipa* e = c.get(id);
    if (!e->getPilotoIds().empty())
        throw DataConsistencyException(
            "Equipa id=" + to_string(id) + " still has pilots assigned");

    c.remove(id);
    m_repo->persist();
}

void EquipaService::update(int id, const EquipaInDTO& dto) {
    RacingApp*       model = m_repo->getModel();
    EquipaContainer& c     = model->getEquipaContainer();
    c.update(id, dto.nome, dto.pais);
    m_repo->persist();
}

void EquipaService::addPiloto(int equipaId, int pilotoId) {
    RacingApp*       model = m_repo->getModel();

    // Verify piloto exists — throws NoDataException if not
    model->getPilotoContainer().get(pilotoId);

    // Verify piloto is not already in another equipa
    Equipa* current = model->getEquipaContainer().findEquipaByPiloto(pilotoId);
    if (current != nullptr)
        throw DataConsistencyException(
            "Piloto id=" + to_string(pilotoId) +
            " already belongs to equipa '" + current->getNome() + "'");

    model->getEquipaContainer().addPiloto(equipaId, pilotoId);
    m_repo->persist();
}

void EquipaService::removePiloto(int equipaId, int pilotoId) {
    RacingApp*       model = m_repo->getModel();
    model->getEquipaContainer().removePiloto(equipaId, pilotoId);
    m_repo->persist();
}
