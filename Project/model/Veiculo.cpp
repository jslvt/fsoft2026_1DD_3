#include "Veiculo.h"
#include <iostream>
#include <iomanip>

Veiculo::Veiculo()
    : m_id(0), m_modelo(""), m_matricula(""), m_ano(0) {}

Veiculo::Veiculo(int id, const std::string& modelo,
                 const std::string& matricula, int ano)
    : m_id(id), m_modelo(modelo), m_matricula(matricula), m_ano(ano) {}

int         Veiculo::getId()        const { return m_id; }
std::string Veiculo::getModelo()    const { return m_modelo; }
std::string Veiculo::getMatricula() const { return m_matricula; }
int         Veiculo::getAno()       const { return m_ano; }

void Veiculo::setId(int id) { m_id = id; }

void Veiculo::print() const {
    std::cout << std::left
              << "[" << std::setw(3) << m_id << "] "
              << std::setw(25) << m_modelo
              << "  Matricula: " << std::setw(12) << m_matricula
              << "  Ano: " << m_ano
              << "\n";
}
