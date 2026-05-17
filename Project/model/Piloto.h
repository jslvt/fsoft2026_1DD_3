#pragma once
#include <string>

class Piloto {
public:
    Piloto();
    Piloto(int id, const std::string& nome,
           const std::string& dataNasc, const std::string& nLicenca);

    int         getId()       const;
    std::string getNome()     const;
    std::string getDataNasc() const;
    std::string getNLicenca() const;

    void setId(int id);

    void print() const;

private:
    int         m_id;
    std::string m_nome;
    std::string m_dataNasc;
    std::string m_nLicenca;
};
