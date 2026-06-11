#include "VeiculoService.h"
#include "VeiculoMapper.h"
#include "RacingApp.h"

VeiculoService::VeiculoService(IRacingRepository* repo) : m_repo(repo) {}

void VeiculoService::add(const VeiculoInDTO& dto) {
    RacingApp*        model = m_repo->getModel();
    VeiculoContainer& c     = model->getVeiculoContainer();
    c.add(dto.modelo, dto.matricula, dto.ano);
    m_repo->persist();
}

void VeiculoService::getAll(list<VeiculoOutDTO>& dtos) {
    RacingApp*        model    = m_repo->getModel();
    VeiculoContainer& c        = model->getVeiculoContainer();
    list<Veiculo*>    veiculos = c.getAll();
    VeiculoMapper::listModel2listDTO(veiculos, dtos);
}

void VeiculoService::getByEquipa(int equipaId, list<VeiculoOutDTO>& dtos) {
    RacingApp*        model    = m_repo->getModel();
    VeiculoContainer& c        = model->getVeiculoContainer();
    list<Veiculo*>    veiculos = c.getByEquipa(equipaId);
    VeiculoMapper::listModel2listDTO(veiculos, dtos);
}

void VeiculoService::get(int id, VeiculoOutDTO& dto) {
    RacingApp*        model = m_repo->getModel();
    VeiculoContainer& c     = model->getVeiculoContainer();
    Veiculo*          v     = c.get(id);
    VeiculoMapper::model2DTO(v, dto);
}

void VeiculoService::remove(int id) {
    RacingApp*        model = m_repo->getModel();
    VeiculoContainer& c     = model->getVeiculoContainer();
    c.remove(id);
    m_repo->persist();
}

void VeiculoService::update(int id, const VeiculoInDTO& dto) {
    RacingApp*        model = m_repo->getModel();
    VeiculoContainer& c     = model->getVeiculoContainer();
    c.update(id, dto.modelo, dto.matricula, dto.ano);
    m_repo->persist();
}

void VeiculoService::assignEquipa(int veiculoId, int equipaId) {
    RacingApp* model = m_repo->getModel();
    // Validate equipa exists — throws NoDataException if not
    model->getEquipaContainer().get(equipaId);
    model->getVeiculoContainer().assignEquipa(veiculoId, equipaId);
    m_repo->persist();
}

void VeiculoService::unassignEquipa(int veiculoId) {
    RacingApp*        model = m_repo->getModel();
    VeiculoContainer& c     = model->getVeiculoContainer();
    c.unassignEquipa(veiculoId);
    m_repo->persist();
}
