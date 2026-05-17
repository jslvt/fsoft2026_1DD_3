#include "Piloto.h"
#include <iostream>
#include <iomanip>

Piloto::Piloto()
    : m_id(0), m_nome(""), m_dataNasc(""), m_nLicenca("") {}

Piloto::Piloto(int id, const std::string& nome,
               const std::string& dataNasc, const std::string& nLicenca)
    : m_id(id), m_nome(nome), m_dataNasc(dataNasc), m_nLicenca(nLicenca) {}

int         Piloto::getId()       const { return m_id; }
std::string Piloto::getNome()     const { return m_nome; }
std::string Piloto::getDataNasc() const { return m_dataNasc; }
std::string Piloto::getNLicenca() const { return m_nLicenca; }

void Piloto::setId(int id) { m_id = id; }

void Piloto::print() const {
    std::cout << std::left
              << "[" << std::setw(3) << m_id << "] "
              << std::setw(30) << m_nome
              << "  Nasc: " << std::setw(12) << m_dataNasc
              << "  Licença: " << m_nLicenca
              << "\n";
}
