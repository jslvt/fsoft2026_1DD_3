#include "Participacao.h"
#include <iostream>
#include <iomanip>

Participacao::Participacao()
    : m_idPiloto(0), m_idCorrida(0), m_posicao(0), m_tempo(0.0f), m_pontos(0) {}

Participacao::Participacao(int idPiloto, int idCorrida,
                           int posicao, float tempo, int pontos)
    : m_idPiloto(idPiloto), m_idCorrida(idCorrida),
      m_posicao(posicao), m_tempo(tempo), m_pontos(pontos) {}

int   Participacao::getIdPiloto()  const { return m_idPiloto; }
int   Participacao::getIdCorrida() const { return m_idCorrida; }
int   Participacao::getPosicao()   const { return m_posicao; }
float Participacao::getTempo()     const { return m_tempo; }
int   Participacao::getPontos()    const { return m_pontos; }

void Participacao::setPontos(int pontos) { m_pontos = pontos; }

void Participacao::print() const {
    std::cout << std::left
              << "  Pos: " << std::setw(4) << m_posicao
              << "  Tempo: " << std::fixed << std::setprecision(3)
              << std::setw(10) << m_tempo << "s"
              << "  Pontos: " << m_pontos
              << "\n";
}
