#pragma once
#include <string>
#include <list>
using namespace std;

class Campeonato {
private:
    int       m_id;
    string    m_nome;
    int       m_ano;
    list<int> m_corridaIds;
    list<int> m_equipaIds;

    static bool isNomeValid(const string& nome);
    static bool isAnoValid(int ano);

public:
    Campeonato(int id, const string& nome, int ano);

    int              getId()        const;
    const string&    getNome()      const;
    int              getAno()       const;
    const list<int>& getCorridaIds() const;
    const list<int>& getEquipaIds()  const;

    void setNome(const string& nome);
    void setAno(int ano);

    // Corrida association
    void addCorrida(int corridaId);
    void removeCorrida(int corridaId);
    bool hasCorrida(int corridaId) const;

    // Equipa association
    void addEquipa(int equipaId);
    void removeEquipa(int equipaId);
    bool hasEquipa(int equipaId) const;

    bool operator==(int id)               const;
    bool operator==(const Campeonato& obj) const;
};
