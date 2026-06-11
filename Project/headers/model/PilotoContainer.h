#pragma once
#include <list>
#include "Piloto.h"
using namespace std;

class PilotoContainer {
private:
    list<Piloto> m_pilotos;
    int          m_nextId;

public:
    PilotoContainer();

    // Add a new piloto — throws DuplicatedDataException if licence exists
    void    add(const string& nome, const string& dataNasc,
                const string& nLicenca);

    // Get by id — throws NoDataException if not found
    Piloto* get(int id);

    // Get by licence — throws NoDataException if not found
    Piloto* getByLicenca(const string& nLicenca);

    // Get all as pointers (service will map to DTOs)
    list<Piloto*> getAll();

    // Remove by id — throws NoDataException if not found
    void remove(int id);

    // Update fields — throws NoDataException if not found
    void update(int id, const string& nome,
                const string& dataNasc, const string& nLicenca);

    // Used by repository to restore persisted data (no duplicate check)
    void restore(int id, const string& nome,
                 const string& dataNasc, const string& nLicenca);

    // Used by repository to restore nextId after loading from file
    void setNextId(int nextId);
    int  getNextId() const;
};
