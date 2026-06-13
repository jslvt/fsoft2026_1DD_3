#pragma once
#include <list>
#include "CampeonatoInDTO.h"
#include "CampeonatoOutDTO.h"
using namespace std;

class CampeonatoView {
public:
    CampeonatoView() = default;

    int menuCampeonatos();

    CampeonatoInDTO getCampeonato();
    int getId();
    int getCorridaId();
    int getEquipaId();

    void printCampeonato(const CampeonatoOutDTO& dto);
    void printCampeonatos(list<CampeonatoOutDTO>& dtos);
    void printClassificacao(int campeonatoId,
                            const string& campeonatoNome,
                            list<pair<string, int>>& classificacao);
};
