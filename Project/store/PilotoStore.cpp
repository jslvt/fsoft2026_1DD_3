#include "PilotoStore.h"
#include "BinaryIO.h"
#include <fstream>
#include <iostream>

PilotoStore::PilotoStore(const std::string& ficheiro)
    : m_ficheiro(ficheiro) {}

void PilotoStore::guardar(const std::vector<Piloto>& pilotos) {
    std::ofstream out(m_ficheiro, std::ios::binary | std::ios::trunc);
    if (!out) {
        std::cerr << "[PilotoStore] Erro ao abrir ficheiro para escrita: "
                  << m_ficheiro << "\n";
        return;
    }
    size_t n = pilotos.size();
    writePOD(out, n);
    for (const auto& p : pilotos) {
        writePOD(out,    p.getId());
        writeString(out, p.getNome());
        writeString(out, p.getDataNasc());
        writeString(out, p.getNLicenca());
    }
}

std::vector<Piloto> PilotoStore::carregar() {
    std::vector<Piloto> pilotos;
    std::ifstream in(m_ficheiro, std::ios::binary);
    if (!in) return pilotos;          // first run: file doesn't exist yet

    size_t n = readPOD<size_t>(in);
    pilotos.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        int         id       = readPOD<int>(in);
        std::string nome     = readString(in);
        std::string dataNasc = readString(in);
        std::string nLicenca = readString(in);
        pilotos.emplace_back(id, nome, dataNasc, nLicenca);
    }
    return pilotos;
}
