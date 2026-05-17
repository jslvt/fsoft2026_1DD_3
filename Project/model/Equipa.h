#pragma once
#include <string>

class Equipa {
public:
    Equipa();
    Equipa(int id, const std::string& nome, const std::string& pais);

    int         getId()   const;
    std::string getNome() const;
    std::string getPais() const;

    void setId(int id);

    void print() const;

private:
    int         m_id;
    std::string m_nome;
    std::string m_pais;
};
