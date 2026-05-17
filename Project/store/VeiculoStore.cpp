#include "VeiculoStore.h"
#include "BinaryIO.h"
#include <fstream>
#include <iostream>

VeiculoStore::VeiculoStore(const std::string& ficheiro)
    : m_ficheiro(ficheiro) {}

void VeiculoStore::guardar(const std::vector<Veiculo>& veiculos) {
    std::ofstream out(m_ficheiro, std::ios::binary | std::ios::trunc);
    if (!out) {
        std::cerr << "[VeiculoStore] Erro ao abrir ficheiro para escrita: "
                  << m_ficheiro << "\n";
        return;
    }
    size_t n = veiculos.size();
    writePOD(out, n);
    for (const auto& v : veiculos) {
        writePOD(out,    v.getId());
        writeString(out, v.getModelo());
        writeString(out, v.getMatricula());
        writePOD(out,    v.getAno());
    }
}

std::vector<Veiculo> VeiculoStore::carregar() {
    std::vector<Veiculo> veiculos;
    std::ifstream in(m_ficheiro, std::ios::binary);
    if (!in) return veiculos;

    size_t n = readPOD<size_t>(in);
    veiculos.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        int         id        = readPOD<int>(in);
        std::string modelo    = readString(in);
        std::string matricula = readString(in);
        int         ano       = readPOD<int>(in);
        veiculos.emplace_back(id, modelo, matricula, ano);
    }
    return veiculos;
}
