#include "EquipaContainer.h"
#include "NoDataException.h"
#include "DuplicatedDataException.h"

EquipaContainer::EquipaContainer() : m_nextId(1) {}

// ── add ───────────────────────────────────────────────────────────────────────

void EquipaContainer::add(const string& nome, const string& pais) {
    for (auto& e : m_equipas)
        if (e == nome)
            throw DuplicatedDataException("Equipa '" + nome + "' already exists");
    m_equipas.emplace_back(m_nextId++, nome, pais);
}

// ── get ───────────────────────────────────────────────────────────────────────

Equipa* EquipaContainer::get(int id) {
    for (auto& e : m_equipas)
        if (e == id)
            return &e;
    throw NoDataException("Equipa id=" + to_string(id) + " not found");
}

list<Equipa*> EquipaContainer::getAll() {
    list<Equipa*> result;
    for (auto& e : m_equipas)
        result.push_back(&e);
    return result;
}

// ── remove ────────────────────────────────────────────────────────────────────

void EquipaContainer::remove(int id) {
    for (auto it = m_equipas.begin(); it != m_equipas.end(); ++it) {
        if (*it == id) {
            m_equipas.erase(it);
            return;
        }
    }
    throw NoDataException("Equipa id=" + to_string(id) + " not found");
}

// ── update ────────────────────────────────────────────────────────────────────

void EquipaContainer::update(int id, const string& nome, const string& pais) {
    Equipa* e = get(id);
    e->setNome(nome);
    e->setPais(pais);
}

// ── pilot association ─────────────────────────────────────────────────────────

void EquipaContainer::addPiloto(int equipaId, int pilotoId) {
    Equipa* e = get(equipaId);   // throws NoDataException if not found
    e->addPiloto(pilotoId);      // throws DuplicatedDataException if already in
}

void EquipaContainer::removePiloto(int equipaId, int pilotoId) {
    Equipa* e = get(equipaId);
    e->removePiloto(pilotoId);   // throws NoDataException if not in equipa
}

Equipa* EquipaContainer::findEquipaByPiloto(int pilotoId) {
    for (auto& e : m_equipas)
        if (e.hasPiloto(pilotoId))
            return &e;
    return nullptr;
}

// ── restore ───────────────────────────────────────────────────────────────────

void EquipaContainer::restore(int id, const string& nome, const string& pais,
                               const list<int>& pilotoIds) {
    m_equipas.emplace_back(id, nome, pais);
    Equipa* e = &m_equipas.back();
    for (int pid : pilotoIds)
        e->addPiloto(pid);
}

void EquipaContainer::setNextId(int nextId) { m_nextId = nextId; }
int  EquipaContainer::getNextId()     const { return m_nextId;   }
