#pragma once
#include <string>

class Corrida {
public:
    Corrida();
    Corrida(int id, const std::string& nome,
            const std::string& circuito, const std::string& data);

    int         getId()      const;
    std::string getNome()    const;
    std::string getCircuito() const;
    std::string getData()    const;

    void setId(int id);

    void print() const;

private:
    int         m_id;
    std::string m_nome;
    std::string m_circuito;
    std::string m_data;
};
