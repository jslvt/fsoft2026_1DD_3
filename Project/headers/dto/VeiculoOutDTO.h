#pragma once
#include <string>
using namespace std;

struct VeiculoOutDTO {
    int    id;
    string modelo;
    string matricula;
    int    ano;
    int    equipaId;   // 0 = unassigned
};
