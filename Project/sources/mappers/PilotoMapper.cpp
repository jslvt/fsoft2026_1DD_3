#include "PilotoMapper.h"

void PilotoMapper::model2DTO(Piloto* obj, PilotoOutDTO& dto) {
    dto.id       = obj->getId();
    dto.nome     = obj->getNome();
    dto.dataNasc = obj->getDataNasc();
    dto.nLicenca = obj->getNLicenca();
}

void PilotoMapper::listModel2listDTO(list<Piloto*>& objs, list<PilotoOutDTO>& dtos) {
    for (auto* p : objs) {
        PilotoOutDTO dto;
        model2DTO(p, dto);
        dtos.push_back(dto);
    }
}