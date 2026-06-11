#include "RacingRepositoryBin.h"
#include <fstream>
#include <filesystem>
#include <iostream>
using namespace std;

// ── Singleton ─────────────────────────────────────────────────────────────────

RacingRepositoryBin* RacingRepositoryBin::s_instance = nullptr;

RacingRepositoryBin* RacingRepositoryBin::getInstance(const string& dataDir) {
    if (s_instance == nullptr)
        s_instance = new RacingRepositoryBin(dataDir);
    return s_instance;
}

RacingRepositoryBin::RacingRepositoryBin(const string& dataDir)
    : m_dataDir(dataDir)
{
    filesystem::create_directories(m_dataDir);
    loadPilotos();
    loadEquipas();
}

// ── Interface ─────────────────────────────────────────────────────────────────

RacingApp* RacingRepositoryBin::getModel() { return &m_model; }

void RacingRepositoryBin::persist() {
    savePilotos();
    saveEquipas();
}

// ── Binary helpers ────────────────────────────────────────────────────────────

static void writeStr(ofstream& out, const string& s) {
    size_t len = s.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(s.data(), static_cast<streamsize>(len));
}

static string readStr(ifstream& in) {
    size_t len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    string s(len, '\0');
    in.read(s.data(), static_cast<streamsize>(len));
    return s;
}

template<typename T> static void writePOD(ofstream& out, const T& v) {
    out.write(reinterpret_cast<const char*>(&v), sizeof(T));
}
template<typename T> static T readPOD(ifstream& in) {
    T v{};
    in.read(reinterpret_cast<char*>(&v), sizeof(T));
    return v;
}

// ── Pilotos ───────────────────────────────────────────────────────────────────

void RacingRepositoryBin::loadPilotos() {
    string path = m_dataDir + "/pilotos.bin";
    ifstream in(path, ios::binary);
    if (!in) return;

    PilotoContainer& c = m_model.getPilotoContainer();
    int    nextId = readPOD<int>(in);
    size_t count  = readPOD<size_t>(in);
    for (size_t i = 0; i < count; ++i) {
        int    id       = readPOD<int>(in);
        string nome     = readStr(in);
        string dataNasc = readStr(in);
        string nLicenca = readStr(in);
        c.restore(id, nome, dataNasc, nLicenca);
    }
    c.setNextId(nextId);
}

void RacingRepositoryBin::savePilotos() {
    string path = m_dataDir + "/pilotos.bin";
    ofstream out(path, ios::binary | ios::trunc);
    if (!out) { cerr << "[Repo] Cannot open " << path << "\n"; return; }

    PilotoContainer& c       = m_model.getPilotoContainer();
    list<Piloto*>    pilotos = c.getAll();
    writePOD(out, c.getNextId());
    writePOD(out, pilotos.size());
    for (Piloto* p : pilotos) {
        writePOD(out,  p->getId());
        writeStr(out,  p->getNome());
        writeStr(out,  p->getDataNasc());
        writeStr(out,  p->getNLicenca());
    }
}

// ── Equipas ───────────────────────────────────────────────────────────────────

void RacingRepositoryBin::loadEquipas() {
    string path = m_dataDir + "/equipas.bin";
    ifstream in(path, ios::binary);
    if (!in) return;

    EquipaContainer& c = m_model.getEquipaContainer();
    int    nextId = readPOD<int>(in);
    size_t count  = readPOD<size_t>(in);
    for (size_t i = 0; i < count; ++i) {
        int    id   = readPOD<int>(in);
        string nome = readStr(in);
        string pais = readStr(in);

        // Read the list of associated piloto ids
        size_t nPilotos = readPOD<size_t>(in);
        list<int> pilotoIds;
        for (size_t j = 0; j < nPilotos; ++j)
            pilotoIds.push_back(readPOD<int>(in));

        c.restore(id, nome, pais, pilotoIds);
    }
    c.setNextId(nextId);
}

void RacingRepositoryBin::saveEquipas() {
    string path = m_dataDir + "/equipas.bin";
    ofstream out(path, ios::binary | ios::trunc);
    if (!out) { cerr << "[Repo] Cannot open " << path << "\n"; return; }

    EquipaContainer& c      = m_model.getEquipaContainer();
    list<Equipa*>    equipas = c.getAll();
    writePOD(out, c.getNextId());
    writePOD(out, equipas.size());
    for (Equipa* e : equipas) {
        writePOD(out,  e->getId());
        writeStr(out,  e->getNome());
        writeStr(out,  e->getPais());
        // Write piloto ids list
        const list<int>& pids = e->getPilotoIds();
        writePOD(out, pids.size());
        for (int pid : pids)
            writePOD(out, pid);
    }
}
