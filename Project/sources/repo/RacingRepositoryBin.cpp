#include "RacingRepositoryBin.h"
#include <fstream>
#include <filesystem>
#include <iostream>
using namespace std;

RacingRepositoryBin* RacingRepositoryBin::s_instance = nullptr;

RacingRepositoryBin* RacingRepositoryBin::getInstance(const string& dataDir) {
    if (s_instance == nullptr)
        s_instance = new RacingRepositoryBin(dataDir);
    return s_instance;
}

RacingRepositoryBin::RacingRepositoryBin(const string& dataDir) : m_dataDir(dataDir) {
    filesystem::create_directories(m_dataDir);
    loadPilotos();
    loadEquipas();
    loadVeiculos();
    loadCorridas();
    loadParticipacoes();
}

RacingApp* RacingRepositoryBin::getModel()  { return &m_model; }

void RacingRepositoryBin::persist() {
    savePilotos();
    saveEquipas();
    saveVeiculos();
    saveCorridas();
    saveParticipacoes();
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
    ifstream in(path, ios::binary); if (!in) return;
    PilotoContainer& c = m_model.getPilotoContainer();
    int nextId = readPOD<int>(in); size_t count = readPOD<size_t>(in);
    for (size_t i = 0; i < count; ++i) {
        int id = readPOD<int>(in); string nome = readStr(in);
        string dataNasc = readStr(in); string nLicenca = readStr(in);
        c.restore(id, nome, dataNasc, nLicenca);
    }
    c.setNextId(nextId);
}
void RacingRepositoryBin::savePilotos() {
    string path = m_dataDir + "/pilotos.bin";
    ofstream out(path, ios::binary | ios::trunc);
    if (!out) { cerr << "[Repo] Cannot open " << path << "\n"; return; }
    PilotoContainer& c = m_model.getPilotoContainer();
    list<Piloto*> pilotos = c.getAll();
    writePOD(out, c.getNextId()); writePOD(out, pilotos.size());
    for (Piloto* p : pilotos) {
        writePOD(out, p->getId()); writeStr(out, p->getNome());
        writeStr(out, p->getDataNasc()); writeStr(out, p->getNLicenca());
    }
}

// ── Equipas ───────────────────────────────────────────────────────────────────

void RacingRepositoryBin::loadEquipas() {
    string path = m_dataDir + "/equipas.bin";
    ifstream in(path, ios::binary); if (!in) return;
    EquipaContainer& c = m_model.getEquipaContainer();
    int nextId = readPOD<int>(in); size_t count = readPOD<size_t>(in);
    for (size_t i = 0; i < count; ++i) {
        int id = readPOD<int>(in); string nome = readStr(in); string pais = readStr(in);
        size_t nPilotos = readPOD<size_t>(in);
        list<int> pilotoIds;
        for (size_t j = 0; j < nPilotos; ++j) pilotoIds.push_back(readPOD<int>(in));
        c.restore(id, nome, pais, pilotoIds);
    }
    c.setNextId(nextId);
}
void RacingRepositoryBin::saveEquipas() {
    string path = m_dataDir + "/equipas.bin";
    ofstream out(path, ios::binary | ios::trunc);
    if (!out) { cerr << "[Repo] Cannot open " << path << "\n"; return; }
    EquipaContainer& c = m_model.getEquipaContainer();
    list<Equipa*> equipas = c.getAll();
    writePOD(out, c.getNextId()); writePOD(out, equipas.size());
    for (Equipa* e : equipas) {
        writePOD(out, e->getId()); writeStr(out, e->getNome()); writeStr(out, e->getPais());
        const list<int>& pids = e->getPilotoIds();
        writePOD(out, pids.size());
        for (int pid : pids) writePOD(out, pid);
    }
}

// ── Veiculos ──────────────────────────────────────────────────────────────────

void RacingRepositoryBin::loadVeiculos() {
    string path = m_dataDir + "/veiculos.bin";
    ifstream in(path, ios::binary); if (!in) return;
    VeiculoContainer& c = m_model.getVeiculoContainer();
    int nextId = readPOD<int>(in); size_t count = readPOD<size_t>(in);
    for (size_t i = 0; i < count; ++i) {
        int id = readPOD<int>(in); string modelo = readStr(in);
        string matricula = readStr(in); int ano = readPOD<int>(in);
        int equipaId = readPOD<int>(in);
        c.restore(id, modelo, matricula, ano, equipaId);
    }
    c.setNextId(nextId);
}
void RacingRepositoryBin::saveVeiculos() {
    string path = m_dataDir + "/veiculos.bin";
    ofstream out(path, ios::binary | ios::trunc);
    if (!out) { cerr << "[Repo] Cannot open " << path << "\n"; return; }
    VeiculoContainer& c = m_model.getVeiculoContainer();
    list<Veiculo*> veiculos = c.getAll();
    writePOD(out, c.getNextId()); writePOD(out, veiculos.size());
    for (Veiculo* v : veiculos) {
        writePOD(out, v->getId()); writeStr(out, v->getModelo());
        writeStr(out, v->getMatricula()); writePOD(out, v->getAno());
        writePOD(out, v->getEquipaId());
    }
}

// ── Corridas ──────────────────────────────────────────────────────────────────

void RacingRepositoryBin::loadCorridas() {
    string path = m_dataDir + "/corridas.bin";
    ifstream in(path, ios::binary); if (!in) return;
    CorridaContainer& c = m_model.getCorridaContainer();
    int nextId = readPOD<int>(in); size_t count = readPOD<size_t>(in);
    for (size_t i = 0; i < count; ++i) {
        int id = readPOD<int>(in); string nome = readStr(in);
        string circuito = readStr(in); string data = readStr(in);
        TipoCorrida tipo = readPOD<TipoCorrida>(in); int campeonatoId = readPOD<int>(in);
        c.restore(id, nome, circuito, data, tipo, campeonatoId);
    }
    c.setNextId(nextId);
}
void RacingRepositoryBin::saveCorridas() {
    string path = m_dataDir + "/corridas.bin";
    ofstream out(path, ios::binary | ios::trunc);
    if (!out) { cerr << "[Repo] Cannot open " << path << "\n"; return; }
    CorridaContainer& c = m_model.getCorridaContainer();
    list<Corrida*> corridas = c.getAll();
    writePOD(out, c.getNextId()); writePOD(out, corridas.size());
    for (Corrida* cr : corridas) {
        writePOD(out, cr->getId()); writeStr(out, cr->getNome());
        writeStr(out, cr->getCircuito()); writeStr(out, cr->getData());
        writePOD(out, cr->getTipo()); writePOD(out, cr->getCampeonatoId());
    }
}

// ── Participacoes ─────────────────────────────────────────────────────────────

void RacingRepositoryBin::loadParticipacoes() {
    string path = m_dataDir + "/participacoes.bin";
    ifstream in(path, ios::binary); if (!in) return;
    ParticipacaoContainer& c = m_model.getParticipacaoContainer();
    size_t count = readPOD<size_t>(in);
    for (size_t i = 0; i < count; ++i) {
        int   pilotoId  = readPOD<int>(in);
        int   corridaId = readPOD<int>(in);
        int   posicao   = readPOD<int>(in);
        float tempo     = readPOD<float>(in);
        int   pontos    = readPOD<int>(in);
        c.restore(pilotoId, corridaId, posicao, tempo, pontos);
    }
}
void RacingRepositoryBin::saveParticipacoes() {
    string path = m_dataDir + "/participacoes.bin";
    ofstream out(path, ios::binary | ios::trunc);
    if (!out) { cerr << "[Repo] Cannot open " << path << "\n"; return; }
    ParticipacaoContainer& c = m_model.getParticipacaoContainer();
    list<Participacao*> participacoes = c.getAll();
    writePOD(out, participacoes.size());
    for (Participacao* p : participacoes) {
        writePOD(out, p->getPilotoId());
        writePOD(out, p->getCorridaId());
        writePOD(out, p->getPosicao());
        writePOD(out, p->getTempo());
        writePOD(out, p->getPontos());
    }
}
