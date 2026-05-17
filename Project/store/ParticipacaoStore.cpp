#include "ParticipacaoStore.h"
#include "BinaryIO.h"
#include <fstream>
#include <iostream>

ParticipacaoStore::ParticipacaoStore(const std::string& ficheiro)
    : m_ficheiro(ficheiro) {}

void ParticipacaoStore::guardar(const std::vector<Participacao>& participacoes) {
    std::ofstream out(m_ficheiro, std::ios::binary | std::ios::trunc);
    if (!out) {
        std::cerr << "[ParticipacaoStore] Erro ao abrir ficheiro para escrita: "
                  << m_ficheiro << "\n";
        return;
    }
    size_t n = participacoes.size();
    writePOD(out, n);
    for (const auto& p : participacoes) {
        writePOD(out, p.getIdPiloto());
        writePOD(out, p.getIdCorrida());
        writePOD(out, p.getPosicao());
        writePOD(out, p.getTempo());
        writePOD(out, p.getPontos());
    }
}

std::vector<Participacao> ParticipacaoStore::carregar() {
    std::vector<Participacao> participacoes;
    std::ifstream in(m_ficheiro, std::ios::binary);
    if (!in) return participacoes;

    size_t n = readPOD<size_t>(in);
    participacoes.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        int   idPiloto  = readPOD<int>(in);
        int   idCorrida = readPOD<int>(in);
        int   posicao   = readPOD<int>(in);
        float tempo     = readPOD<float>(in);
        int   pontos    = readPOD<int>(in);
        participacoes.emplace_back(idPiloto, idCorrida, posicao, tempo, pontos);
    }
    return participacoes;
}
