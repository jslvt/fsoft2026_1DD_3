#include "Corrida.h"
#include <iostream>
#include <iomanip>

Corrida::Corrida()
    : m_id(0), m_nome(""), m_circuito(""), m_data("") {}

Corrida::Corrida(int id, const std::string& nome,
                 const std::string& circuito, const std::string& data)
    : m_id(id), m_nome(nome), m_circuito(circuito), m_data(data) {}

int         Corrida::getId()       const { return m_id; }
std::string Corrida::getNome()     const { return m_nome; }
std::string Corrida::getCircuito() const { return m_circuito; }
std::string Corrida::getData()     const { return m_data; }

void Corrida::setId(int id) { m_id = id; }

void Corrida::print() const {
    std::cout << std::left
              << "[" << std::setw(3) << m_id << "] "
              << std::setw(30) << m_nome
              << "  Circuito: " << std::setw(25) << m_circuito
              << "  Data: " << m_data
              << "\n";
}
