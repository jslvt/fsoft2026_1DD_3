#pragma once
#include <list>
#include "Veiculo.h"
using namespace std;

class VeiculoContainer {
private:
    list<Veiculo> m_veiculos;
    int           m_nextId;

public:
    VeiculoContainer();

    // Add — throws DuplicatedDataException if matricula exists
    void add(const string& modelo, const string& matricula,
             int ano, int equipaId = 0);

    // Get by id — throws NoDataException if not found
    Veiculo* get(int id);

    // Get all as pointers
    list<Veiculo*> getAll();

    // Get all veiculos belonging to a given equipa
    list<Veiculo*> getByEquipa(int equipaId);

    // Remove — throws NoDataException if not found
    void remove(int id);

    // Update fields — throws NoDataException if not found
    void update(int id, const string& modelo,
                const string& matricula, int ano);

    // Assign / unassign equipa
    void assignEquipa(int veiculoId, int equipaId);
    void unassignEquipa(int veiculoId);

    // Used by repository on load
    void restore(int id, const string& modelo,
                 const string& matricula, int ano, int equipaId);

    void setNextId(int nextId);
    int  getNextId() const;
};
