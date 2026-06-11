#include "Controller.h"
#include <iostream>
using namespace std;

Controller::Controller(PilotoService*  pilotoService,
                       EquipaService*  equipaService,
                       VeiculoService* veiculoService)
    : m_pilotoService(pilotoService),
      m_equipaService(equipaService),
      m_veiculoService(veiculoService) {}

// ── Main loop ─────────────────────────────────────────────────────────────────

void Controller::run() {
    int op;
    do {
        op = m_view.menuPrincipal();
        switch (op) {
            case 1: runPilotos();  break;
            case 2: runEquipas();  break;
            case 3: runVeiculos(); break;
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
                case 1: { PilotoInDTO dto = m_pilotoView.getPiloto();
                          m_pilotoService->add(dto);
                          m_view.printMessage("Piloto adicionado com sucesso."); break; }
                case 2: { int id = m_pilotoView.getId(); PilotoOutDTO dto;
                          m_pilotoService->get(id, dto);
                          m_pilotoView.printPiloto(dto); break; }
                case 3: { int id = m_pilotoView.getId();
                          m_pilotoService->remove(id);
                          m_view.printMessage("Piloto removido com sucesso."); break; }
                case 4: { int id = m_pilotoView.getId();
                          PilotoInDTO dto = m_pilotoView.getPiloto();
                          m_pilotoService->update(id, dto);
                          m_view.printMessage("Piloto atualizado com sucesso."); break; }
                case 5: { list<PilotoOutDTO> dtos;
                          m_pilotoService->getAll(dtos);
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
                case 1: { EquipaInDTO dto = m_equipaView.getEquipa();
                          m_equipaService->add(dto);
                          m_view.printMessage("Equipa adicionada com sucesso."); break; }
                case 2: { int id = m_equipaView.getId(); EquipaOutDTO dto;
                          m_equipaService->get(id, dto);
                          m_equipaView.printEquipa(dto); break; }
                case 3: { int id = m_equipaView.getId();
                          m_equipaService->remove(id);
                          m_view.printMessage("Equipa removida com sucesso."); break; }
                case 4: { int id = m_equipaView.getId();
                          EquipaInDTO dto = m_equipaView.getEquipa();
                          m_equipaService->update(id, dto);
                          m_view.printMessage("Equipa atualizada com sucesso."); break; }
                case 5: { list<EquipaOutDTO> dtos;
                          m_equipaService->getAll(dtos);
                          m_equipaView.printEquipas(dtos); break; }
                case 6: { int eId = m_equipaView.getId();
                          int pId = m_equipaView.getPilotoId();
                          m_equipaService->addPiloto(eId, pId);
                          m_view.printMessage("Piloto adicionado a equipa."); break; }
                case 7: { int eId = m_equipaView.getId();
                          int pId = m_equipaView.getPilotoId();
                          m_equipaService->removePiloto(eId, pId);
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
                case 1: { VeiculoInDTO dto = m_veiculoView.getVeiculo();
                          m_veiculoService->add(dto);
                          m_view.printMessage("Veiculo adicionado com sucesso."); break; }
                case 2: { int id = m_veiculoView.getId(); VeiculoOutDTO dto;
                          m_veiculoService->get(id, dto);
                          m_veiculoView.printVeiculo(dto); break; }
                case 3: { int id = m_veiculoView.getId();
                          m_veiculoService->remove(id);
                          m_view.printMessage("Veiculo removido com sucesso."); break; }
                case 4: { int id = m_veiculoView.getId();
                          VeiculoInDTO dto = m_veiculoView.getVeiculo();
                          m_veiculoService->update(id, dto);
                          m_view.printMessage("Veiculo atualizado com sucesso."); break; }
                case 5: { list<VeiculoOutDTO> dtos;
                          m_veiculoService->getAll(dtos);
                          m_veiculoView.printVeiculos(dtos); break; }
                case 6: { int eId = m_veiculoView.getEquipaId();
                          list<VeiculoOutDTO> dtos;
                          m_veiculoService->getByEquipa(eId, dtos);
                          m_veiculoView.printVeiculos(dtos); break; }
                case 7: { int vId = m_veiculoView.getId();
                          int eId = m_veiculoView.getEquipaId();
                          m_veiculoService->assignEquipa(vId, eId);
                          m_view.printMessage("Veiculo associado a equipa."); break; }
                case 8: { int vId = m_veiculoView.getId();
                          m_veiculoService->unassignEquipa(vId);
                          m_view.printMessage("Veiculo desassociado da equipa."); break; }
                default: break;
            }
        } catch (const exception& e) { m_view.printError(e.what()); }
        if (op != 0) m_view.pausar();
    } while (op != 0);
}
