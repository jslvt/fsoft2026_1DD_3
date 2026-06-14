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
    RacingApp*       model   = m_repo->getModel();
    EquipaContainer& c       = model->getEquipaContainer();
    list<Equipa*>    equipas = c.getAll();
    EquipaMapper::listModel2listDTO(equipas, dtos);
}

void EquipaService::get(int id, EquipaOutDTO& dto) {
    RacingApp*       model = m_repo->getModel();
    EquipaContainer& c     = model->getEquipaContainer();
    Equipa*          e     = c.get(id);
    EquipaMapper::model2DTO(e, dto);
}

void EquipaService::remove(int id) {
    RacingApp*       model = m_repo->getModel();
    EquipaContainer& c     = model->getEquipaContainer();
    Equipa*          e     = c.get(id);

    // Refuse if equipa still has pilots
    if (!e->getPilotoIds().empty())
        throw DataConsistencyException(
            "Equipa id=" + to_string(id) +
            " still has pilots assigned — remove pilots first");

    // Refuse if equipa has vehicles assigned
    list<Veiculo*> veiculos =
        model->getVeiculoContainer().getByEquipa(id);
    if (!veiculos.empty())
        throw DataConsistencyException(
            "Equipa id=" + to_string(id) +
            " still has vehicles assigned — unassign vehicles first");

    // Refuse if equipa is inscribed in a campeonato
    list<Campeonato*> campeonatos =
        model->getCampeonatoContainer().getAll();
    for (auto* camp : campeonatos) {
        if (camp->hasEquipa(id))
            throw DataConsistencyException(
                "Equipa id=" + to_string(id) +
                " is inscribed in campeonato '" + camp->getNome() +
                "' — remove from campeonato first");
    }

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
    RacingApp* model = m_repo->getModel();
    model->getPilotoContainer().get(pilotoId);
    Equipa* current = model->getEquipaContainer().findEquipaByPiloto(pilotoId);
    if (current != nullptr)
        throw DataConsistencyException(
            "Piloto id=" + to_string(pilotoId) +
            " already belongs to equipa '" + current->getNome() + "'");
    model->getEquipaContainer().addPiloto(equipaId, pilotoId);
    m_repo->persist();
}

void EquipaService::removePiloto(int equipaId, int pilotoId) {
    m_repo->getModel()->getEquipaContainer().removePiloto(equipaId, pilotoId);
    m_repo->persist();
}