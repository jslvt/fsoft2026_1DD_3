#include "Controller.h"
#include <iostream>
using namespace std;

Controller::Controller(PilotoService* pilotoService,
                       EquipaService* equipaService)
    : m_pilotoService(pilotoService),
      m_equipaService(equipaService) {}

// ── Main loop ─────────────────────────────────────────────────────────────────

void Controller::run() {
    int op;
    do {
        op = m_view.menuPrincipal();
        switch (op) {
            case 1: runPilotos(); break;
            case 2: runEquipas(); break;
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
                case 1: {
                    PilotoInDTO dto = m_pilotoView.getPiloto();
                    m_pilotoService->add(dto);
                    m_view.printMessage("Piloto adicionado com sucesso.");
                    break;
                }
                case 2: {
                    int id = m_pilotoView.getId();
                    PilotoOutDTO dto;
                    m_pilotoService->get(id, dto);
                    m_pilotoView.printPiloto(dto);
                    break;
                }
                case 3: {
                    int id = m_pilotoView.getId();
                    m_pilotoService->remove(id);
                    m_view.printMessage("Piloto removido com sucesso.");
                    break;
                }
                case 4: {
                    int id = m_pilotoView.getId();
                    PilotoInDTO dto = m_pilotoView.getPiloto();
                    m_pilotoService->update(id, dto);
                    m_view.printMessage("Piloto atualizado com sucesso.");
                    break;
                }
                case 5: {
                    list<PilotoOutDTO> dtos;
                    m_pilotoService->getAll(dtos);
                    m_pilotoView.printPilotos(dtos);
                    break;
                }
                default: break;
            }
        } catch (const exception& e) {
            m_view.printError(e.what());
        }
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
                case 1: {
                    EquipaInDTO dto = m_equipaView.getEquipa();
                    m_equipaService->add(dto);
                    m_view.printMessage("Equipa adicionada com sucesso.");
                    break;
                }
                case 2: {
                    int id = m_equipaView.getId();
                    EquipaOutDTO dto;
                    m_equipaService->get(id, dto);
                    m_equipaView.printEquipa(dto);
                    break;
                }
                case 3: {
                    int id = m_equipaView.getId();
                    m_equipaService->remove(id);
                    m_view.printMessage("Equipa removida com sucesso.");
                    break;
                }
                case 4: {
                    int id = m_equipaView.getId();
                    EquipaInDTO dto = m_equipaView.getEquipa();
                    m_equipaService->update(id, dto);
                    m_view.printMessage("Equipa atualizada com sucesso.");
                    break;
                }
                case 5: {
                    list<EquipaOutDTO> dtos;
                    m_equipaService->getAll(dtos);
                    m_equipaView.printEquipas(dtos);
                    break;
                }
                case 6: {
                    int equipaId = m_equipaView.getId();
                    int pilotoId = m_equipaView.getPilotoId();
                    m_equipaService->addPiloto(equipaId, pilotoId);
                    m_view.printMessage("Piloto adicionado a equipa com sucesso.");
                    break;
                }
                case 7: {
                    int equipaId = m_equipaView.getId();
                    int pilotoId = m_equipaView.getPilotoId();
                    m_equipaService->removePiloto(equipaId, pilotoId);
                    m_view.printMessage("Piloto removido da equipa com sucesso.");
                    break;
                }
                default: break;
            }
        } catch (const exception& e) {
            m_view.printError(e.what());
        }
        if (op != 0) m_view.pausar();
    } while (op != 0);
}
