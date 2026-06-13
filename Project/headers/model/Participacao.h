#pragma once
using namespace std;

class Participacao {
private:
    int   m_pilotoId;
    int   m_corridaId;
    int   m_posicao;
    float m_tempo;
    int   m_pontos;

    static bool isPosicaoValid(int posicao);
    static bool isTempoValid(float tempo);

public:
    Participacao(int pilotoId, int corridaId,
                 int posicao, float tempo, int pontos = 0);

    int   getPilotoId()  const;
    int   getCorridaId() const;
    int   getPosicao()   const;
    float getTempo()     const;
    int   getPontos()    const;

    void setPosicao(int posicao);
    void setTempo(float tempo);
    void setPontos(int pontos);

    // Equality — a participation is unique per piloto+corrida pair
    bool operator==(const Participacao& obj) const;
};
