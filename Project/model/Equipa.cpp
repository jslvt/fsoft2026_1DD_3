#include "Equipa.h"
#include <iostream>
#include <iomanip>

Equipa::Equipa()
    : m_id(0), m_nome(""), m_pais("") {}

Equipa::Equipa(int id, const std::string& nome, const std::string& pais)
    : m_id(id), m_nome(nome), m_pais(pais) {}

int         Equipa::getId()   const { return m_id; }
std::string Equipa::getNome() const { return m_nome; }
std::string Equipa::getPais() const { return m_pais; }

void Equipa::setId(int id) { m_id = id; }

void Equipa::print() const {
    std::cout << std::left
              << "[" << std::setw(3) << m_id << "] "
              << std::setw(30) << m_nome
              << "  Pais: " << m_pais
              << "\n";
}
