#include "PilotoContainer.h"
#include "NoDataException.h"
#include "DuplicatedDataException.h"

PilotoContainer::PilotoContainer() : m_nextId(1) {}

// ── add ───────────────────────────────────────────────────────────────────────

void PilotoContainer::add(const string& nome, const string& dataNasc,
                           const string& nLicenca) {
    // Check for duplicate licence
    for (auto& p : m_pilotos)
        if (p == nLicenca)
            throw DuplicatedDataException("Licenca '" + nLicenca + "' already exists");

    // Piloto constructor validates and throws InvalidDataException if bad
    m_pilotos.emplace_back(m_nextId++, nome, dataNasc, nLicenca);
}

// ── get ───────────────────────────────────────────────────────────────────────

Piloto* PilotoContainer::get(int id) {
    for (auto& p : m_pilotos)
        if (p == id)
            return &p;
    throw NoDataException("Piloto id=" + to_string(id) + " not found");
}

Piloto* PilotoContainer::getByLicenca(const string& nLicenca) {
    for (auto& p : m_pilotos)
        if (p == nLicenca)
            return &p;
    throw NoDataException("Piloto licenca='" + nLicenca + "' not found");
}

list<Piloto*> PilotoContainer::getAll() {
    list<Piloto*> result;
    for (auto& p : m_pilotos)
        result.push_back(&p);
    return result;
}

// ── remove ────────────────────────────────────────────────────────────────────

void PilotoContainer::remove(int id) {
    for (auto it = m_pilotos.begin(); it != m_pilotos.end(); ++it) {
        if (*it == id) {
            m_pilotos.erase(it);
            return;
        }
    }
    throw NoDataException("Piloto id=" + to_string(id) + " not found");
}

// ── update ────────────────────────────────────────────────────────────────────

void PilotoContainer::update(int id, const string& nome,
                              const string& dataNasc, const string& nLicenca) {
    Piloto* p = get(id);   // throws NoDataException if not found
    p->setNome(nome);
    p->setDataNasc(dataNasc);
    p->setNLicenca(nLicenca);
}

// ── restore (used by repository on load) ─────────────────────────────────────

void PilotoContainer::restore(int id, const string& nome,
                               const string& dataNasc, const string& nLicenca) {
    // No duplicate check — data coming from trusted persisted source
    m_pilotos.emplace_back(id, nome, dataNasc, nLicenca);
}

void PilotoContainer::setNextId(int nextId) { m_nextId = nextId; }
int  PilotoContainer::getNextId()     const { return m_nextId;   }
