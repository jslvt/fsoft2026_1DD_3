#include "Equipa.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"
#include "NoDataException.h"
#include <algorithm>

// ── Validation ────────────────────────────────────────────────────────────────

bool Equipa::isNomeValid(const string& nome) {
    return nome.length() >= 2;
}

// ── Constructor ───────────────────────────────────────────────────────────────

Equipa::Equipa(int id, const string& nome, const string& pais) {
    if (id <= 0)
        throw InvalidDataException("Equipa id must be > 0");
    m_id = id;
    setNome(nome);
    setPais(pais);
}

// ── Getters ───────────────────────────────────────────────────────────────────

int               Equipa::getId()          const { return m_id;         }
const string&     Equipa::getNome()        const { return m_nome;       }
const string&     Equipa::getPais()        const { return m_pais;       }
const list<int>&  Equipa::getPilotoIds()   const { return m_pilotoIds;  }

// ── Setters ───────────────────────────────────────────────────────────────────

void Equipa::setNome(const string& nome) {
    if (!isNomeValid(nome))
        throw InvalidDataException("Equipa nome '" + nome + "' is too short");
    m_nome = nome;
}

void Equipa::setPais(const string& pais) {
    if (pais.empty())
        throw InvalidDataException("Equipa pais cannot be empty");
    m_pais = pais;
}

// ── Pilot association ─────────────────────────────────────────────────────────

void Equipa::addPiloto(int pilotoId) {
    if (hasPiloto(pilotoId))
        throw DuplicatedDataException(
            "Piloto id=" + to_string(pilotoId) + " already in equipa");
    m_pilotoIds.push_back(pilotoId);
}

void Equipa::removePiloto(int pilotoId) {
    auto it = find(m_pilotoIds.begin(), m_pilotoIds.end(), pilotoId);
    if (it == m_pilotoIds.end())
        throw NoDataException(
            "Piloto id=" + to_string(pilotoId) + " not in equipa");
    m_pilotoIds.erase(it);
}

bool Equipa::hasPiloto(int pilotoId) const {
    return find(m_pilotoIds.begin(), m_pilotoIds.end(), pilotoId)
           != m_pilotoIds.end();
}

// ── Operators ─────────────────────────────────────────────────────────────────

bool Equipa::operator==(int id)             const { return m_id   == id;   }
bool Equipa::operator==(const string& nome) const { return m_nome == nome; }
bool Equipa::operator==(const Equipa& obj)  const { return m_id   == obj.m_id; }
