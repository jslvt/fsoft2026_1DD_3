#pragma once
#include <string>
#include "TipoCorrida.h"
using namespace std;

struct CorridaOutDTO {
    int         id;
    string      nome;
    string      circuito;
    string      data;
    TipoCorrida tipo;
    string      tipoStr;       // "Normal" or "Campeonato"
    int         campeonatoId;  // 0 = not assigned
};
