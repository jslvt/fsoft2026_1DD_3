#pragma once
#include <list>
#include "Equipa.h"
using namespace std;

class EquipaContainer {
private:
    list<Equipa> m_equipas;
    int          m_nextId;

public:
    EquipaContainer();

    // Add new equipa — throws DuplicatedDataException if name exists
    void add(const string& nome, const string& pais);

    // Get by id — throws NoDataException if not found
    Equipa* get(int id);

    // Get all as pointers
    list<Equipa*> getAll();

    // Remove — throws NoDataException if not found
    void remove(int id);

    // Update fields — throws NoDataException if not found
    void update(int id, const string& nome, const string& pais);

    // Associate / disassociate a piloto from an equipa
    void addPiloto(int equipaId, int pilotoId);
    void removePiloto(int equipaId, int pilotoId);

    // Find which equipa a piloto belongs to (nullptr if none)
    Equipa* findEquipaByPiloto(int pilotoId);

    // Used by repository on load — no duplicate check
    void restore(int id, const string& nome, const string& pais,
                 const list<int>& pilotoIds);

    void setNextId(int nextId);
    int  getNextId() const;
};
