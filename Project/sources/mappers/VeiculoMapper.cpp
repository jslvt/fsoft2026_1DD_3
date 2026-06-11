#include "VeiculoMapper.h"

void VeiculoMapper::model2DTO(Veiculo* obj, VeiculoOutDTO& dto) {
    dto.id        = obj->getId();
    dto.modelo    = obj->getModelo();
    dto.matricula = obj->getMatricula();
    dto.ano       = obj->getAno();
    dto.equipaId  = obj->getEquipaId();
}

void VeiculoMapper::listModel2listDTO(list<Veiculo*>& objs, list<VeiculoOutDTO>& dtos) {
    for (auto* v : objs) {
        VeiculoOutDTO dto;
        model2DTO(v, dto);
        dtos.push_back(dto);
    }
}
