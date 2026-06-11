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
}

// ── Interface ─────────────────────────────────────────────────────────────────

RacingApp* RacingRepositoryBin::getModel() {
    return &m_model;
}

void RacingRepositoryBin::persist() {
    savePilotos();
}

// ── Binary helpers ────────────────────────────────────────────────────────────

static void writeString(ofstream& out, const string& s) {
    size_t len = s.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(s.data(), static_cast<streamsize>(len));
}

static string readString(ifstream& in) {
    size_t len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    string s(len, '\0');
    in.read(s.data(), static_cast<streamsize>(len));
    return s;
}

template<typename T>
static void writePOD(ofstream& out, const T& v) {
    out.write(reinterpret_cast<const char*>(&v), sizeof(T));
}

template<typename T>
static T readPOD(ifstream& in) {
    T v{};
    in.read(reinterpret_cast<char*>(&v), sizeof(T));
    return v;
}

// ── Load ──────────────────────────────────────────────────────────────────────

void RacingRepositoryBin::loadPilotos() {
    string path = m_dataDir + "/pilotos.bin";
    ifstream in(path, ios::binary);
    if (!in) return;   // first run — file doesn't exist yet

    PilotoContainer& container = m_model.getPilotoContainer();

    int nextId    = readPOD<int>(in);
    size_t count  = readPOD<size_t>(in);

    for (size_t i = 0; i < count; ++i) {
        int    id       = readPOD<int>(in);
        string nome     = readString(in);
        string dataNasc = readString(in);
        string nLicenca = readString(in);
        container.restore(id, nome, dataNasc, nLicenca);
    }
    container.setNextId(nextId);
}

// ── Save ──────────────────────────────────────────────────────────────────────

void RacingRepositoryBin::savePilotos() {
    string path = m_dataDir + "/pilotos.bin";
    ofstream out(path, ios::binary | ios::trunc);
    if (!out) {
        cerr << "[Repo] Could not open " << path << " for writing\n";
        return;
    }

    PilotoContainer& container = m_model.getPilotoContainer();
    list<Piloto*>    pilotos   = container.getAll();

    writePOD(out, container.getNextId());
    writePOD(out, pilotos.size());

    for (Piloto* p : pilotos) {
        writePOD(out,    p->getId());
        writeString(out, p->getNome());
        writeString(out, p->getDataNasc());
        writeString(out, p->getNLicenca());
    }
}
