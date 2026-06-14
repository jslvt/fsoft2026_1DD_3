#include "Corrida.h"
#include "Validator.h"
#include "InvalidDataException.h"

bool Corrida::isNomeValid(const string& nome)         { return nome.length() >= 2;     }
bool Corrida::isCircuitoValid(const string& circuito) { return circuito.length() >= 2; }

Corrida::Corrida(int id, const string& nome, const string& circuito,
                 const string& data, TipoCorrida tipo, int campeonatoId) {
    if (id <= 0)
        throw InvalidDataException("Corrida id must be > 0");
    m_id           = id;
    m_tipo         = tipo;
    m_campeonatoId = campeonatoId;
    setNome(nome);
    setCircuito(circuito);
    setData(data);
}

int           Corrida::getId()           const { return m_id;           }
const string& Corrida::getNome()         const { return m_nome;         }
const string& Corrida::getCircuito()     const { return m_circuito;     }
const string& Corrida::getData()         const { return m_data;         }
TipoCorrida   Corrida::getTipo()         const { return m_tipo;         }
int           Corrida::getCampeonatoId() const { return m_campeonatoId; }

string Corrida::getTipoStr() const {
    return m_tipo == TipoCorrida::CAMPEONATO ? "Campeonato" : "Normal";
}

void Corrida::setNome(const string& nome) {
    if (!isNomeValid(nome))
        throw InvalidDataException("Corrida nome '" + nome + "' is too short");
    m_nome = nome;
}

void Corrida::setCircuito(const string& circuito) {
    if (!isCircuitoValid(circuito))
        throw InvalidDataException("Corrida circuito '" + circuito + "' is too short");
    m_circuito = circuito;
}

void Corrida::setData(const string& data) {
    if (!Validator::isDateValid(data))
        throw InvalidDataException("Corrida data: " + Validator::dateError());
    m_data = data;
}

void Corrida::setTipo(TipoCorrida tipo)         { m_tipo         = tipo;         }
void Corrida::setCampeonatoId(int campeonatoId) { m_campeonatoId = campeonatoId; }

bool Corrida::operator==(int id)             const { return m_id == id;       }
bool Corrida::operator==(const Corrida& obj) const { return m_id == obj.m_id; }