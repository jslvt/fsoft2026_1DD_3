#include "ParticipacaoMapper.h"

void ParticipacaoMapper::model2DTO(Participacao* obj, ParticipacaoOutDTO& dto,
                                    const string& pilotoNome,
                                    const string& corridaNome) {
    dto.pilotoId    = obj->getPilotoId();
    dto.corridaId   = obj->getCorridaId();
    dto.posicao     = obj->getPosicao();
    dto.tempo       = obj->getTempo();
    dto.pontos      = obj->getPontos();
    dto.pilotoNome  = pilotoNome;
    dto.corridaNome = corridaNome;
}

void ParticipacaoMapper::listModel2listDTO(list<Participacao*>& objs,
                                            list<ParticipacaoOutDTO>& dtos,
                                            const string& pilotoNome,
                                            const string& corridaNome) {
    for (auto* p : objs) {
        ParticipacaoOutDTO dto;
        model2DTO(p, dto, pilotoNome, corridaNome);
        dtos.push_back(dto);
    }
}
