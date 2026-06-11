#include "EquipaMapper.h"

void EquipaMapper::model2DTO(Equipa* obj, EquipaOutDTO& dto) {
    dto.id        = obj->getId();
    dto.nome      = obj->getNome();
    dto.pais      = obj->getPais();
    dto.pilotoIds = obj->getPilotoIds();
}

void EquipaMapper::listModel2listDTO(list<Equipa*>& objs, list<EquipaOutDTO>& dtos) {
    for (auto* e : objs) {
        EquipaOutDTO dto;
        model2DTO(e, dto);
        dtos.push_back(dto);
    }
}
