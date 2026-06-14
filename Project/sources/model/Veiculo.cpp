#include "Veiculo.h"
#include "Validator.h"
#include "InvalidDataException.h"

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

int           Veiculo::getId()        const { return m_id;        }
const string& Veiculo::getModelo()    const { return m_modelo;    }
const string& Veiculo::getMatricula() const { return m_matricula; }
int           Veiculo::getAno()       const { return m_ano;       }
int           Veiculo::getEquipaId()  const { return m_equipaId;  }

void Veiculo::setModelo(const string& modelo) {
    if (modelo.size() < 2)
        throw InvalidDataException("Veiculo modelo is too short");
    m_modelo = modelo;
}

void Veiculo::setMatricula(const string& matricula) {
    if (!Validator::isMatriculaValid(matricula))
        throw InvalidDataException("Veiculo matricula: " + Validator::matriculaError());
    m_matricula = matricula;
}

void Veiculo::setAno(int ano) {
    if (!Validator::isAnoValid(ano))
        throw InvalidDataException("Veiculo ano: " + Validator::anoError());
    m_ano = ano;
}

void Veiculo::setEquipaId(int equipaId) { m_equipaId = equipaId; }

bool Veiculo::operator==(int id)             const { return m_id        == id;   }
bool Veiculo::operator==(const string& matr) const { return m_matricula == matr; }
bool Veiculo::operator==(const Veiculo& obj) const { return m_id        == obj.m_id; }