#pragma once
#include <string>
#include <list>
using namespace std;

struct EquipaOutDTO {
    int       id;
    string    nome;
    string    pais;
    list<int> pilotoIds;   // ids of associated pilots
};
