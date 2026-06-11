#include "Controller.h"
#include <iostream>
using namespace std;

Controller::Controller(PilotoService* pilotoService)
    : m_pilotoService(pilotoService) {}

// ── Main loop ─────────────────────────────────────────────────────────────────

void Controller::run() {
    int op;
    do {
        op = m_view.menuPrincipal();
        switch (op) {
            case 1: runPilotos(); break;
            // case 2: runEquipas();  break;  — future iterations
            // case 3: runVeiculos(); break;
            // case 4: runCorridas(); break;
            // case 5: runParticipacoes(); break;
            // case 6: runCampeonatos(); break;
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
                    // Adicionar
                    PilotoInDTO dto = m_pilotoView.getPiloto();
                    m_pilotoService->add(dto);
                    m_view.printMessage("Piloto adicionado com sucesso.");
                    break;
                }
                case 2: {
                    // Consultar
                    int id = m_pilotoView.getId();
                    PilotoOutDTO dto;
                    m_pilotoService->get(id, dto);
                    m_pilotoView.printPiloto(dto);
                    break;
                }
                case 3: {
                    // Remover
                    int id = m_pilotoView.getId();
                    m_pilotoService->remove(id);
                    m_view.printMessage("Piloto removido com sucesso.");
                    break;
                }
                case 4: {
                    // Atualizar
                    int id = m_pilotoView.getId();
                    PilotoInDTO dto = m_pilotoView.getPiloto();
                    m_pilotoService->update(id, dto);
                    m_view.printMessage("Piloto atualizado com sucesso.");
                    break;
                }
                case 5: {
                    // Listar todos
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
