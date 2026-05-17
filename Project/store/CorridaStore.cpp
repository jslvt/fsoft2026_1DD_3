#include "CorridaStore.h"
#include "BinaryIO.h"
#include <fstream>
#include <iostream>

CorridaStore::CorridaStore(const std::string& ficheiro)
    : m_ficheiro(ficheiro) {}

void CorridaStore::guardar(const std::vector<Corrida>& corridas) {
    std::ofstream out(m_ficheiro, std::ios::binary | std::ios::trunc);
    if (!out) {
        std::cerr << "[CorridaStore] Erro ao abrir ficheiro para escrita: "
                  << m_ficheiro << "\n";
        return;
    }
    size_t n = corridas.size();
    writePOD(out, n);
    for (const auto& c : corridas) {
        writePOD(out,    c.getId());
        writeString(out, c.getNome());
        writeString(out, c.getCircuito());
        writeString(out, c.getData());
    }
}

std::vector<Corrida> CorridaStore::carregar() {
    std::vector<Corrida> corridas;
    std::ifstream in(m_ficheiro, std::ios::binary);
    if (!in) return corridas;

    size_t n = readPOD<size_t>(in);
    corridas.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        int         id       = readPOD<int>(in);
        std::string nome     = readString(in);
        std::string circuito = readString(in);
        std::string data     = readString(in);
        corridas.emplace_back(id, nome, circuito, data);
    }
    return corridas;
}
