#pragma once
#include <string>

class Veiculo {
public:
    Veiculo();
    Veiculo(int id, const std::string& modelo,
            const std::string& matricula, int ano);

    int         getId()       const;
    std::string getModelo()   const;
    std::string getMatricula() const;
    int         getAno()      const;

    void setId(int id);

    void print() const;

private:
    int         m_id;
    std::string m_modelo;
    std::string m_matricula;
    int         m_ano;
};
