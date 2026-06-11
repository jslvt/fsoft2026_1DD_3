#include "CorridaMapper.h"

void CorridaMapper::model2DTO(Corrida* obj, CorridaOutDTO& dto) {
    dto.id           = obj->getId();
    dto.nome         = obj->getNome();
    dto.circuito     = obj->getCircuito();
    dto.data         = obj->getData();
    dto.tipo         = obj->getTipo();
    dto.tipoStr      = obj->getTipoStr();
    dto.campeonatoId = obj->getCampeonatoId();
}

void CorridaMapper::listModel2listDTO(list<Corrida*>& objs, list<CorridaOutDTO>& dtos) {
    for (auto* c : objs) {
        CorridaOutDTO dto;
        model2DTO(c, dto);
        dtos.push_back(dto);
    }
}
