#pragma once
#include <list>
#include "Campeonato.h"
using namespace std;

class CampeonatoContainer {
private:
    list<Campeonato> m_campeonatos;
    int              m_nextId;

public:
    CampeonatoContainer();

    void add(const string& nome, int ano);

    Campeonato* get(int id);
    list<Campeonato*> getAll();

    void remove(int id);
    void update(int id, const string& nome, int ano);

    void addCorrida(int campeonatoId, int corridaId);
    void removeCorrida(int campeonatoId, int corridaId);

    void addEquipa(int campeonatoId, int equipaId);
    void removeEquipa(int campeonatoId, int equipaId);

    void restore(int id, const string& nome, int ano,
                 const list<int>& corridaIds, const list<int>& equipaIds);

    void setNextId(int nextId);
    int  getNextId() const;
};
