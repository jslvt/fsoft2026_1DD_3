#include "VeiculoContainer.h"
#include "NoDataException.h"
#include "DuplicatedDataException.h"

VeiculoContainer::VeiculoContainer() : m_nextId(1) {}

// ── add ───────────────────────────────────────────────────────────────────────

void VeiculoContainer::add(const string& modelo, const string& matricula,
                            int ano, int equipaId) {
    for (auto& v : m_veiculos)
        if (v == matricula)
            throw DuplicatedDataException("Matricula '" + matricula + "' already exists");
    m_veiculos.emplace_back(m_nextId++, modelo, matricula, ano, equipaId);
}

// ── get ───────────────────────────────────────────────────────────────────────

Veiculo* VeiculoContainer::get(int id) {
    for (auto& v : m_veiculos)
        if (v == id)
            return &v;
    throw NoDataException("Veiculo id=" + to_string(id) + " not found");
}

list<Veiculo*> VeiculoContainer::getAll() {
    list<Veiculo*> result;
    for (auto& v : m_veiculos)
        result.push_back(&v);
    return result;
}

list<Veiculo*> VeiculoContainer::getByEquipa(int equipaId) {
    list<Veiculo*> result;
    for (auto& v : m_veiculos)
        if (v.getEquipaId() == equipaId)
            result.push_back(&v);
    return result;
}

// ── remove ────────────────────────────────────────────────────────────────────

void VeiculoContainer::remove(int id) {
    for (auto it = m_veiculos.begin(); it != m_veiculos.end(); ++it) {
        if (*it == id) {
            m_veiculos.erase(it);
            return;
        }
    }
    throw NoDataException("Veiculo id=" + to_string(id) + " not found");
}

// ── update ────────────────────────────────────────────────────────────────────

void VeiculoContainer::update(int id, const string& modelo,
                               const string& matricula, int ano) {
    Veiculo* v = get(id);
    v->setModelo(modelo);
    v->setMatricula(matricula);
    v->setAno(ano);
}

// ── equipa assignment ─────────────────────────────────────────────────────────

void VeiculoContainer::assignEquipa(int veiculoId, int equipaId) {
    Veiculo* v = get(veiculoId);
    v->setEquipaId(equipaId);
}

void VeiculoContainer::unassignEquipa(int veiculoId) {
    Veiculo* v = get(veiculoId);
    v->setEquipaId(0);
}

// ── restore ───────────────────────────────────────────────────────────────────

void VeiculoContainer::restore(int id, const string& modelo,
                                const string& matricula, int ano, int equipaId) {
    m_veiculos.emplace_back(id, modelo, matricula, ano, equipaId);
}

void VeiculoContainer::setNextId(int nextId) { m_nextId = nextId; }
int  VeiculoContainer::getNextId()     const { return m_nextId;   }
