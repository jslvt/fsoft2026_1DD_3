#include "Campeonato.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"
#include "NoDataException.h"
#include <algorithm>

bool Campeonato::isNomeValid(const string& nome) { return nome.length() >= 2; }
bool Campeonato::isAnoValid(int ano)              { return ano >= 1900 && ano <= 2100; }

Campeonato::Campeonato(int id, const string& nome, int ano) {
    if (id <= 0) throw InvalidDataException("Campeonato id must be > 0");
    m_id = id;
    setNome(nome);
    setAno(ano);
}

int              Campeonato::getId()         const { return m_id;         }
const string&    Campeonato::getNome()       const { return m_nome;       }
int              Campeonato::getAno()        const { return m_ano;        }
const list<int>& Campeonato::getCorridaIds() const { return m_corridaIds; }
const list<int>& Campeonato::getEquipaIds()  const { return m_equipaIds;  }

void Campeonato::setNome(const string& nome) {
    if (!isNomeValid(nome))
        throw InvalidDataException("Campeonato nome '" + nome + "' is too short");
    m_nome = nome;
}
void Campeonato::setAno(int ano) {
    if (!isAnoValid(ano))
        throw InvalidDataException("Campeonato ano " + to_string(ano) + " is out of range");
    m_ano = ano;
}

// ── Corrida association ───────────────────────────────────────────────────────

void Campeonato::addCorrida(int corridaId) {
    if (hasCorrida(corridaId))
        throw DuplicatedDataException(
            "Corrida id=" + to_string(corridaId) + " already in campeonato");
    m_corridaIds.push_back(corridaId);
}
void Campeonato::removeCorrida(int corridaId) {
    auto it = find(m_corridaIds.begin(), m_corridaIds.end(), corridaId);
    if (it == m_corridaIds.end())
        throw NoDataException(
            "Corrida id=" + to_string(corridaId) + " not in campeonato");
    m_corridaIds.erase(it);
}
bool Campeonato::hasCorrida(int corridaId) const {
    return find(m_corridaIds.begin(), m_corridaIds.end(), corridaId)
           != m_corridaIds.end();
}

// ── Equipa association ────────────────────────────────────────────────────────

void Campeonato::addEquipa(int equipaId) {
    if (hasEquipa(equipaId))
        throw DuplicatedDataException(
            "Equipa id=" + to_string(equipaId) + " already in campeonato");
    m_equipaIds.push_back(equipaId);
}
void Campeonato::removeEquipa(int equipaId) {
    auto it = find(m_equipaIds.begin(), m_equipaIds.end(), equipaId);
    if (it == m_equipaIds.end())
        throw NoDataException(
            "Equipa id=" + to_string(equipaId) + " not in campeonato");
    m_equipaIds.erase(it);
}
bool Campeonato::hasEquipa(int equipaId) const {
    return find(m_equipaIds.begin(), m_equipaIds.end(), equipaId)
           != m_equipaIds.end();
}

// ── Operators ─────────────────────────────────────────────────────────────────

bool Campeonato::operator==(int id)                const { return m_id == id;        }
bool Campeonato::operator==(const Campeonato& obj) const { return m_id == obj.m_id;  }
