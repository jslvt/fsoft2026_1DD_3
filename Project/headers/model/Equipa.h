#pragma once
#include <string>
#include <list>
using namespace std;

class Equipa {
private:
    int    m_id;
    string m_nome;
    string m_pais;
    list<int> m_pilotoIds;   // ids of pilots belonging to this team

    static bool isNomeValid(const string& nome);

public:
    Equipa(int id, const string& nome, const string& pais);

    // Getters
    int               getId()   const;
    const string&     getNome() const;
    const string&     getPais() const;
    const list<int>&  getPilotoIds() const;

    // Setters — throw InvalidDataException on bad input
    void setNome(const string& nome);
    void setPais(const string& pais);

    // Pilot association
    void addPiloto(int pilotoId);
    void removePiloto(int pilotoId);
    bool hasPiloto(int pilotoId) const;

    // Equality operators
    bool operator==(int id)            const;
    bool operator==(const string& nome) const;
    bool operator==(const Equipa& obj) const;
};