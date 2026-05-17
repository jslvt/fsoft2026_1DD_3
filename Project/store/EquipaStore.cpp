#include "EquipaStore.h"
#include "BinaryIO.h"
#include <fstream>
#include <iostream>

EquipaStore::EquipaStore(const std::string& ficheiro)
    : m_ficheiro(ficheiro) {}

void EquipaStore::guardar(const std::vector<Equipa>& equipas) {
    std::ofstream out(m_ficheiro, std::ios::binary | std::ios::trunc);
    if (!out) {
        std::cerr << "[EquipaStore] Erro ao abrir ficheiro para escrita: "
                  << m_ficheiro << "\n";
        return;
    }
    size_t n = equipas.size();
    writePOD(out, n);
    for (const auto& e : equipas) {
        writePOD(out,    e.getId());
        writeString(out, e.getNome());
        writeString(out, e.getPais());
    }
}

std::vector<Equipa> EquipaStore::carregar() {
    std::vector<Equipa> equipas;
    std::ifstream in(m_ficheiro, std::ios::binary);
    if (!in) return equipas;

    size_t n = readPOD<size_t>(in);
    equipas.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        int         id   = readPOD<int>(in);
        std::string nome = readString(in);
        std::string pais = readString(in);
        equipas.emplace_back(id, nome, pais);
    }
    return equipas;
}
