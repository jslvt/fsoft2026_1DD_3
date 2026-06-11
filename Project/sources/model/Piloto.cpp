#include "../../headers/model/Piloto.h"
#include "InvalidDataException.h"

// ── Validation ────────────────────────────────────────────────────────────────

bool Piloto::isNomeValid(const string& nome) {
    return nome.length() >= 2;
}

bool Piloto::isLicencaValid(const string& nLicenca) {
    return nLicenca.length() >= 3;
}

// ── Constructor ───────────────────────────────────────────────────────────────

Piloto::Piloto(int id, const string& nome,
               const string& dataNasc, const string& nLicenca) {
    if (id <= 0)
        throw InvalidDataException("Piloto id must be > 0");
    m_id = id;

    setNome(nome);
    setDataNasc(dataNasc);
    setNLicenca(nLicenca);
}

// ── Getters ───────────────────────────────────────────────────────────────────

int           Piloto::getId()       const { return m_id; }
const string& Piloto::getNome()     const { return m_nome; }
const string& Piloto::getDataNasc() const { return m_dataNasc; }
const string& Piloto::getNLicenca() const { return m_nLicenca; }

// ── Setters ───────────────────────────────────────────────────────────────────

void Piloto::setNome(const string& nome) {
    if (!isNomeValid(nome))
        throw InvalidDataException("Piloto nome '" + nome + "' is too short");
    m_nome = nome;
}

void Piloto::setDataNasc(const string& dataNasc) {
    if (dataNasc.empty())
        throw InvalidDataException("Piloto dataNasc cannot be empty");
    m_dataNasc = dataNasc;
}

void Piloto::setNLicenca(const string& nLicenca) {
    if (!isLicencaValid(nLicenca))
        throw InvalidDataException("Piloto nLicenca '" + nLicenca + "' is too short");
    m_nLicenca = nLicenca;
}

// ── Operators ─────────────────────────────────────────────────────────────────

bool Piloto::operator==(int id)            const { return m_id       == id;  }
bool Piloto::operator==(const string& lic) const { return m_nLicenca == lic; }
bool Piloto::operator==(const Piloto& obj) const { return m_id       == obj.m_id; }
