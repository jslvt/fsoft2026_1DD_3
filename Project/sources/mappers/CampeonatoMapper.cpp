#include "CampeonatoMapper.h"

void CampeonatoMapper::model2DTO(Campeonato* obj, CampeonatoOutDTO& dto) {
    dto.id         = obj->getId();
    dto.nome       = obj->getNome();
    dto.ano        = obj->getAno();
    dto.corridaIds = obj->getCorridaIds();
    dto.equipaIds  = obj->getEquipaIds();
}

void CampeonatoMapper::listModel2listDTO(list<Campeonato*>& objs,
                                          list<CampeonatoOutDTO>& dtos) {
    for (auto* c : objs) {
        CampeonatoOutDTO dto;
        model2DTO(c, dto);
        dtos.push_back(dto);
    }
}
