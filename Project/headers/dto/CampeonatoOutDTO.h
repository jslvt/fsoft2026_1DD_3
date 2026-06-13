#pragma once
#include <string>
#include <list>
using namespace std;

struct CampeonatoOutDTO {
    int       id;
    string    nome;
    int       ano;
    list<int> corridaIds;
    list<int> equipaIds;
};
