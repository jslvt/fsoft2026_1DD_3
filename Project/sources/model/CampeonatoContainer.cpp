#include "CampeonatoContainer.h"
#include "NoDataException.h"
#include "DuplicatedDataException.h"

CampeonatoContainer::CampeonatoContainer() : m_nextId(1) {}

void CampeonatoContainer::add(const string& nome, int ano) {
    m_campeonatos.emplace_back(m_nextId++, nome, ano);
}

Campeonato* CampeonatoContainer::get(int id) {
    for (auto& c : m_campeonatos)
        if (c == id) return &c;
    throw NoDataException("Campeonato id=" + to_string(id) + " not found");
}

list<Campeonato*> CampeonatoContainer::getAll() {
    list<Campeonato*> result;
    for (auto& c : m_campeonatos) result.push_back(&c);
    return result;
}

void CampeonatoContainer::remove(int id) {
    for (auto it = m_campeonatos.begin(); it != m_campeonatos.end(); ++it) {
        if (*it == id) { m_campeonatos.erase(it); return; }
    }
    throw NoDataException("Campeonato id=" + to_string(id) + " not found");
}

void CampeonatoContainer::update(int id, const string& nome, int ano) {
    Campeonato* c = get(id);
    c->setNome(nome);
    c->setAno(ano);
}

void CampeonatoContainer::addCorrida(int campeonatoId, int corridaId) {
    get(campeonatoId)->addCorrida(corridaId);
}
void CampeonatoContainer::removeCorrida(int campeonatoId, int corridaId) {
    get(campeonatoId)->removeCorrida(corridaId);
}

void CampeonatoContainer::addEquipa(int campeonatoId, int equipaId) {
    get(campeonatoId)->addEquipa(equipaId);
}
void CampeonatoContainer::removeEquipa(int campeonatoId, int equipaId) {
    get(campeonatoId)->removeEquipa(equipaId);
}

void CampeonatoContainer::restore(int id, const string& nome, int ano,
                                   const list<int>& corridaIds,
                                   const list<int>& equipaIds) {
    m_campeonatos.emplace_back(id, nome, ano);
    Campeonato* c = &m_campeonatos.back();
    for (int cid : corridaIds) c->addCorrida(cid);
    for (int eid : equipaIds)  c->addEquipa(eid);
}

void CampeonatoContainer::setNextId(int nextId) { m_nextId = nextId; }
int  CampeonatoContainer::getNextId()     const { return m_nextId;   }
