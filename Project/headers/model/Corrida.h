#pragma once
#include <string>
#include "TipoCorrida.h"
using namespace std;

class Corrida {
private:
    int         m_id;
    string      m_nome;
    string      m_circuito;
    string      m_data;
    TipoCorrida m_tipo;
    int         m_campeonatoId;   // 0 = not part of any championship

    static bool isNomeValid(const string& nome);
    static bool isCircuitoValid(const string& circuito);

public:
    Corrida(int id, const string& nome, const string& circuito,
            const string& data, TipoCorrida tipo, int campeonatoId = 0);

    // Getters
    int           getId()           const;
    const string& getNome()         const;
    const string& getCircuito()     const;
    const string& getData()         const;
    TipoCorrida   getTipo()         const;
    int           getCampeonatoId() const;
    string        getTipoStr()      const;  // returns "Normal" or "Campeonato"

    // Setters
    void setNome(const string& nome);
    void setCircuito(const string& circuito);
    void setData(const string& data);
    void setTipo(TipoCorrida tipo);
    void setCampeonatoId(int campeonatoId);

    // Equality operators
    bool operator==(int id)            const;
    bool operator==(const Corrida& obj) const;
};
