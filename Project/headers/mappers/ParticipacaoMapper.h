#pragma once
#include <list>
#include "Participacao.h"
#include "ParticipacaoOutDTO.h"
using namespace std;

class ParticipacaoMapper {
public:
    static void model2DTO(Participacao* obj, ParticipacaoOutDTO& dto,
                          const string& pilotoNome, const string& corridaNome);

    static void listModel2listDTO(list<Participacao*>& objs,
                                  list<ParticipacaoOutDTO>& dtos,
                                  const string& pilotoNome,
                                  const string& corridaNome);
};
