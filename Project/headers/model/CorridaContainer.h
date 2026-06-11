#pragma once
#include <list>
#include "Corrida.h"
using namespace std;

class CorridaContainer {
private:
    list<Corrida> m_corridas;
    int           m_nextId;

public:
    CorridaContainer();

    void add(const string& nome, const string& circuito,
             const string& data, TipoCorrida tipo, int campeonatoId = 0);

    Corrida* get(int id);
    list<Corrida*> getAll();
    list<Corrida*> getByCampeonato(int campeonatoId);

    void remove(int id);
    void update(int id, const string& nome, const string& circuito,
                const string& data, TipoCorrida tipo);

    void assignCampeonato(int corridaId, int campeonatoId);
    void unassignCampeonato(int corridaId);

    void restore(int id, const string& nome, const string& circuito,
                 const string& data, TipoCorrida tipo, int campeonatoId);

    void setNextId(int nextId);
    int  getNextId() const;
};
