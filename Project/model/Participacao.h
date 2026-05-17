#pragma once

class Participacao {
public:
    Participacao();
    Participacao(int idPiloto, int idCorrida,
                 int posicao, float tempo, int pontos = 0);

    int   getIdPiloto()  const;
    int   getIdCorrida() const;
    int   getPosicao()   const;
    float getTempo()     const;
    int   getPontos()    const;

    void setPontos(int pontos);

    void print() const;

private:
    int   m_idPiloto;
    int   m_idCorrida;
    int   m_posicao;
    float m_tempo;
    int   m_pontos;
};
