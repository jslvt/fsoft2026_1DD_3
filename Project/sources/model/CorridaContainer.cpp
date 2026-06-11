#include "CorridaContainer.h"
#include "NoDataException.h"

CorridaContainer::CorridaContainer() : m_nextId(1) {}

void CorridaContainer::add(const string& nome, const string& circuito,
                            const string& data, TipoCorrida tipo, int campeonatoId) {
    m_corridas.emplace_back(m_nextId++, nome, circuito, data, tipo, campeonatoId);
}

Corrida* CorridaContainer::get(int id) {
    for (auto& c : m_corridas)
        if (c == id) return &c;
    throw NoDataException("Corrida id=" + to_string(id) + " not found");
}

list<Corrida*> CorridaContainer::getAll() {
    list<Corrida*> result;
    for (auto& c : m_corridas) result.push_back(&c);
    return result;
}

list<Corrida*> CorridaContainer::getByCampeonato(int campeonatoId) {
    list<Corrida*> result;
    for (auto& c : m_corridas)
        if (c.getCampeonatoId() == campeonatoId)
            result.push_back(&c);
    return result;
}

void CorridaContainer::remove(int id) {
    for (auto it = m_corridas.begin(); it != m_corridas.end(); ++it) {
        if (*it == id) { m_corridas.erase(it); return; }
    }
    throw NoDataException("Corrida id=" + to_string(id) + " not found");
}

void CorridaContainer::update(int id, const string& nome, const string& circuito,
                               const string& data, TipoCorrida tipo) {
    Corrida* c = get(id);
    c->setNome(nome);
    c->setCircuito(circuito);
    c->setData(data);
    c->setTipo(tipo);
}

void CorridaContainer::assignCampeonato(int corridaId, int campeonatoId) {
    get(corridaId)->setCampeonatoId(campeonatoId);
}

void CorridaContainer::unassignCampeonato(int corridaId) {
    get(corridaId)->setCampeonatoId(0);
}

void CorridaContainer::restore(int id, const string& nome, const string& circuito,
                                const string& data, TipoCorrida tipo, int campeonatoId) {
    m_corridas.emplace_back(id, nome, circuito, data, tipo, campeonatoId);
}

void CorridaContainer::setNextId(int nextId) { m_nextId = nextId; }
int  CorridaContainer::getNextId()     const { return m_nextId;   }
