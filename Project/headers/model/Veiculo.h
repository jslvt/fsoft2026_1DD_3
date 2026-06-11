#pragma once
#include <string>
using namespace std;

class Veiculo {
private:
    int    m_id;
    string m_modelo;
    string m_matricula;
    int    m_ano;
    int    m_equipaId;   // 0 = not assigned to any equipa yet

    static bool isModeloValid(const string& modelo);
    static bool isMatriculaValid(const string& matricula);
    static bool isAnoValid(int ano);

public:
    Veiculo(int id, const string& modelo,
            const string& matricula, int ano, int equipaId = 0);

    // Getters
    int           getId()        const;
    const string& getModelo()    const;
    const string& getMatricula() const;
    int           getAno()       const;
    int           getEquipaId()  const;

    // Setters — throw InvalidDataException on bad input
    void setModelo(const string& modelo);
    void setMatricula(const string& matricula);
    void setAno(int ano);
    void setEquipaId(int equipaId);

    // Equality operators
    bool operator==(int id)              const;
    bool operator==(const string& matr)  const;
    bool operator==(const Veiculo& obj)  const;
};
