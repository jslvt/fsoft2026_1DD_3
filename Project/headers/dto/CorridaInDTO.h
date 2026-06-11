#pragma once
#include <string>
#include "TipoCorrida.h"
using namespace std;

struct CorridaInDTO {
    string      nome;
    string      circuito;
    string      data;
    TipoCorrida tipo;
};
