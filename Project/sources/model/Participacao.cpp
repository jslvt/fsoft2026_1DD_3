#include "Participacao.h"
#include "InvalidDataException.h"

bool Participacao::isPosicaoValid(int posicao) { return posicao >= 1; }
bool Participacao::isTempoValid(float tempo)   { return tempo > 0.0f; }

Participacao::Participacao(int pilotoId, int corridaId,
                           int posicao, float tempo, int pontos) {
    if (pilotoId  <= 0) throw InvalidDataException("Participacao pilotoId must be > 0");
    if (corridaId <= 0) throw InvalidDataException("Participacao corridaId must be > 0");
    m_pilotoId  = pilotoId;
    m_corridaId = corridaId;
    m_pontos    = pontos;
    setPosicao(posicao);
    setTempo(tempo);
}

int   Participacao::getPilotoId()  const { return m_pilotoId;  }
int   Participacao::getCorridaId() const { return m_corridaId; }
int   Participacao::getPosicao()   const { return m_posicao;   }
float Participacao::getTempo()     const { return m_tempo;     }
int   Participacao::getPontos()    const { return m_pontos;    }

void Participacao::setPosicao(int posicao) {
    if (!isPosicaoValid(posicao))
        throw InvalidDataException("Participacao posicao must be >= 1");
    m_posicao = posicao;
}

void Participacao::setTempo(float tempo) {
    if (!isTempoValid(tempo))
        throw InvalidDataException("Participacao tempo must be > 0");
    m_tempo = tempo;
}

void Participacao::setPontos(int pontos) { m_pontos = pontos; }

bool Participacao::operator==(const Participacao& obj) const {
    return m_pilotoId == obj.m_pilotoId && m_corridaId == obj.m_corridaId;
}
