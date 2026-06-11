#pragma once
#include <string>
using namespace std;

class Piloto {
private:
    int    m_id;
    string m_nome;
    string m_dataNasc;
    string m_nLicenca;

    // Validation helpers — throw InvalidDataException if invalid
    static bool isNomeValid(const string& nome);
    static bool isLicencaValid(const string& nLicenca);

public:
    Piloto(int id, const string& nome,
           const string& dataNasc, const string& nLicenca);

    // Getters
    int           getId()       const;
    const string& getNome()     const;
    const string& getDataNasc() const;
    const string& getNLicenca() const;

    // Setters — validate and throw InvalidDataException on bad input
    void setNome(const string& nome);
    void setDataNasc(const string& dataNasc);
    void setNLicenca(const string& nLicenca);

    // Equality operators — used by container lookups
    bool operator==(int id)            const;
    bool operator==(const string& lic) const;
    bool operator==(const Piloto& obj) const;
};
