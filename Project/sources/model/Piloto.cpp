#include "Piloto.h"
#include "Validator.h"
#include "InvalidDataException.h"

Piloto::Piloto(int id, const string& nome,
               const string& dataNasc, const string& nLicenca) {
    if (id <= 0)
        throw InvalidDataException("Piloto id must be > 0");
    m_id = id;
    setNome(nome);
    setDataNasc(dataNasc);
    setNLicenca(nLicenca);
}

int           Piloto::getId()       const { return m_id;       }
const string& Piloto::getNome()     const { return m_nome;     }
const string& Piloto::getDataNasc() const { return m_dataNasc; }
const string& Piloto::getNLicenca() const { return m_nLicenca; }

void Piloto::setNome(const string& nome) {
    if (!Validator::isNomeValid(nome))
        throw InvalidDataException("Piloto nome: " + Validator::nomeError());
    m_nome = nome;
}

void Piloto::setDataNasc(const string& dataNasc) {
    if (!Validator::isDateValid(dataNasc))
        throw InvalidDataException("Piloto dataNasc: " + Validator::dateError());
    m_dataNasc = dataNasc;
}

void Piloto::setNLicenca(const string& nLicenca) {
    if (!Validator::isLicencaValid(nLicenca))
        throw InvalidDataException("Piloto nLicenca: " + Validator::licencaError());
    m_nLicenca = nLicenca;
}

bool Piloto::operator==(int id)            const { return m_id       == id;  }
bool Piloto::operator==(const string& lic) const { return m_nLicenca == lic; }
bool Piloto::operator==(const Piloto& obj) const { return m_id       == obj.m_id; }