#include "Controller.h"
#include <iostream>
using namespace std;

Controller::Controller(PilotoService*       pilotoService,
                       EquipaService*       equipaService,
                       VeiculoService*      veiculoService,
                       CorridaService*      corridaService,
                       ParticipacaoService* participacaoService)
    : m_pilotoService(pilotoService),
      m_equipaService(equipaService),
      m_veiculoService(veiculoService),
      m_corridaService(corridaService),
      m_participacaoService(participacaoService) {}

void Controller::run() {
    int op;
    do {
        op = m_view.menuPrincipal();
        switch (op) {
            case 1: runPilotos();       break;
            case 2: runEquipas();       break;
            case 3: runVeiculos();      break;
            case 4: runCorridas();      break;
            case 5: runParticipacoes(); break;
            default: break;
        }
    } while (op != 0);
}

// ── Pilotos ───────────────────────────────────────────────────────────────────

void Controller::runPilotos() {
    int op;
    do {
        op = m_pilotoView.menuPilotos();
        try {
            switch (op) {
                case 1: { m_pilotoService->add(m_pilotoView.getPiloto());
                          m_view.printMessage("Piloto adicionado com sucesso."); break; }
                case 2: { int id = m_pilotoView.getId(); PilotoOutDTO dto;
                          m_pilotoService->get(id, dto); m_pilotoView.printPiloto(dto); break; }
                case 3: { m_pilotoService->remove(m_pilotoView.getId());
                          m_view.printMessage("Piloto removido com sucesso."); break; }
                case 4: { int id = m_pilotoView.getId();
                          m_pilotoService->update(id, m_pilotoView.getPiloto());
                          m_view.printMessage("Piloto atualizado com sucesso."); break; }
                case 5: { list<PilotoOutDTO> dtos; m_pilotoService->getAll(dtos);
                          m_pilotoView.printPilotos(dtos); break; }
                default: break;
            }
        } catch (const exception& e) { m_view.printError(e.what()); }
        if (op != 0) m_view.pausar();
    } while (op != 0);
}

// ── Equipas ───────────────────────────────────────────────────────────────────

void Controller::runEquipas() {
    int op;
    do {
        op = m_equipaView.menuEquipas();
        try {
            switch (op) {
                case 1: { m_equipaService->add(m_equipaView.getEquipa());
                          m_view.printMessage("Equipa adicionada com sucesso."); break; }
                case 2: { int id = m_equipaView.getId(); EquipaOutDTO dto;
                          m_equipaService->get(id, dto); m_equipaView.printEquipa(dto); break; }
                case 3: { m_equipaService->remove(m_equipaView.getId());
                          m_view.printMessage("Equipa removida com sucesso."); break; }
                case 4: { int id = m_equipaView.getId();
                          m_equipaService->update(id, m_equipaView.getEquipa());
                          m_view.printMessage("Equipa atualizada com sucesso."); break; }
                case 5: { list<EquipaOutDTO> dtos; m_equipaService->getAll(dtos);
                          m_equipaView.printEquipas(dtos); break; }
                case 6: { m_equipaService->addPiloto(m_equipaView.getId(), m_equipaView.getPilotoId());
                          m_view.printMessage("Piloto adicionado a equipa."); break; }
                case 7: { m_equipaService->removePiloto(m_equipaView.getId(), m_equipaView.getPilotoId());
                          m_view.printMessage("Piloto removido da equipa."); break; }
                default: break;
            }
        } catch (const exception& e) { m_view.printError(e.what()); }
        if (op != 0) m_view.pausar();
    } while (op != 0);
}

// ── Veiculos ──────────────────────────────────────────────────────────────────

void Controller::runVeiculos() {
    int op;
    do {
        op = m_veiculoView.menuVeiculos();
        try {
            switch (op) {
                case 1: { m_veiculoService->add(m_veiculoView.getVeiculo());
                          m_view.printMessage("Veiculo adicionado com sucesso."); break; }
                case 2: { int id = m_veiculoView.getId(); VeiculoOutDTO dto;
                          m_veiculoService->get(id, dto); m_veiculoView.printVeiculo(dto); break; }
                case 3: { m_veiculoService->remove(m_veiculoView.getId());
                          m_view.printMessage("Veiculo removido com sucesso."); break; }
                case 4: { int id = m_veiculoView.getId();
                          m_veiculoService->update(id, m_veiculoView.getVeiculo());
                          m_view.printMessage("Veiculo atualizado com sucesso."); break; }
                case 5: { list<VeiculoOutDTO> dtos; m_veiculoService->getAll(dtos);
                          m_veiculoView.printVeiculos(dtos); break; }
                case 6: { int eId = m_veiculoView.getEquipaId();
                          list<VeiculoOutDTO> dtos; m_veiculoService->getByEquipa(eId, dtos);
                          m_veiculoView.printVeiculos(dtos); break; }
                case 7: { m_veiculoService->assignEquipa(m_veiculoView.getId(), m_veiculoView.getEquipaId());
                          m_view.printMessage("Veiculo associado a equipa."); break; }
                case 8: { m_veiculoService->unassignEquipa(m_veiculoView.getId());
                          m_view.printMessage("Veiculo desassociado da equipa."); break; }
                default: break;
            }
        } catch (const exception& e) { m_view.printError(e.what()); }
        if (op != 0) m_view.pausar();
    } while (op != 0);
}

// ── Corridas ──────────────────────────────────────────────────────────────────

void Controller::runCorridas() {
    int op;
    do {
        op = m_corridaView.menuCorridas();
        try {
            switch (op) {
                case 1: { m_corridaService->add(m_corridaView.getCorrida());
                          m_view.printMessage("Corrida adicionada com sucesso."); break; }
                case 2: { int id = m_corridaView.getId(); CorridaOutDTO dto;
                          m_corridaService->get(id, dto); m_corridaView.printCorrida(dto); break; }
                case 3: { m_corridaService->remove(m_corridaView.getId());
                          m_view.printMessage("Corrida removida com sucesso."); break; }
                case 4: { int id = m_corridaView.getId();
                          m_corridaService->update(id, m_corridaView.getCorrida());
                          m_view.printMessage("Corrida atualizada com sucesso."); break; }
                case 5: { list<CorridaOutDTO> dtos; m_corridaService->getAll(dtos);
                          m_corridaView.printCorridas(dtos); break; }
                case 6: { int cId = m_corridaView.getCampeonatoId();
                          list<CorridaOutDTO> dtos;
                          m_corridaService->getByCampeonato(cId, dtos);
                          m_corridaView.printCorridas(dtos); break; }
                case 7: { m_corridaService->assignCampeonato(
                              m_corridaView.getId(), m_corridaView.getCampeonatoId());
                          m_view.printMessage("Corrida associada ao campeonato."); break; }
                case 8: { m_corridaService->unassignCampeonato(m_corridaView.getId());
                          m_view.printMessage("Corrida desassociada do campeonato."); break; }
                default: break;
            }
        } catch (const exception& e) { m_view.printError(e.what()); }
        if (op != 0) m_view.pausar();
    } while (op != 0);
}

// ── Participacoes ─────────────────────────────────────────────────────────────

void Controller::runParticipacoes() {
    int op;
    do {
        op = m_participacaoView.menuParticipacoes();
        try {
            switch (op) {
                case 1: { m_participacaoService->add(m_participacaoView.getParticipacao());
                          m_view.printMessage("Resultado registado com sucesso."); break; }
                case 2: { int cId = m_participacaoView.getCorridaId();
                          list<ParticipacaoOutDTO> dtos;
                          m_participacaoService->getByCorrida(cId, dtos);
                          m_participacaoView.printParticipacoes(dtos); break; }
                case 3: { int pId = m_participacaoView.getPilotoId();
                          list<ParticipacaoOutDTO> dtos;
                          m_participacaoService->getByPiloto(pId, dtos);
                          m_participacaoView.printParticipacoes(dtos); break; }
                case 4: { auto classificacao = m_participacaoService->getClassificacaoGeral();
                          m_participacaoView.printClassificacaoGeral(classificacao); break; }
                case 5: { int pId = m_participacaoView.getPilotoId();
                          int cId = m_participacaoView.getCorridaId();
                          m_participacaoService->remove(pId, cId);
                          m_view.printMessage("Resultado removido com sucesso."); break; }
                case 6: { m_participacaoService->update(m_participacaoView.getParticipacao());
                          m_view.printMessage("Resultado atualizado com sucesso."); break; }
                default: break;
            }
        } catch (const exception& e) { m_view.printError(e.what()); }
        if (op != 0) m_view.pausar();
    } while (op != 0);
}
