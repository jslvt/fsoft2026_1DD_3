#include "Veiculo.h"
#include "InvalidDataException.h"

// ── Validation ────────────────────────────────────────────────────────────────

bool Veiculo::isModeloValid(const string& modelo) {
    return modelo.length() >= 2;
}

bool Veiculo::isMatriculaValid(const string& matricula) {
    return matricula.length() >= 3;
}

bool Veiculo::isAnoValid(int ano) {
    return ano >= 1900 && ano <= 2100;
}

// ── Constructor ───────────────────────────────────────────────────────────────

Veiculo::Veiculo(int id, const string& modelo,
                 const string& matricula, int ano, int equipaId) {
    if (id <= 0)
        throw InvalidDataException("Veiculo id must be > 0");
    m_id       = id;
    m_equipaId = equipaId;
    setModelo(modelo);
    setMatricula(matricula);
    setAno(ano);
}

// ── Getters ───────────────────────────────────────────────────────────────────

int           Veiculo::getId()        const { return m_id;        }
const string& Veiculo::getModelo()    const { return m_modelo;    }
const string& Veiculo::getMatricula() const { return m_matricula; }
int           Veiculo::getAno()       const { return m_ano;       }
int           Veiculo::getEquipaId()  const { return m_equipaId;  }

// ── Setters ───────────────────────────────────────────────────────────────────

void Veiculo::setModelo(const string& modelo) {
    if (!isModeloValid(modelo))
        throw InvalidDataException("Veiculo modelo '" + modelo + "' is too short");
    m_modelo = modelo;
}

void Veiculo::setMatricula(const string& matricula) {
    if (!isMatriculaValid(matricula))
        throw InvalidDataException("Veiculo matricula '" + matricula + "' is invalid");
    m_matricula = matricula;
}

void Veiculo::setAno(int ano) {
    if (!isAnoValid(ano))
        throw InvalidDataException("Veiculo ano " + to_string(ano) + " is out of range");
    m_ano = ano;
}

void Veiculo::setEquipaId(int equipaId) {
    m_equipaId = equipaId;
}

// ── Operators ─────────────────────────────────────────────────────────────────

bool Veiculo::operator==(int id)             const { return m_id        == id;   }
bool Veiculo::operator==(const string& matr) const { return m_matricula == matr; }
bool Veiculo::operator==(const Veiculo& obj) const { return m_id        == obj.m_id; }
