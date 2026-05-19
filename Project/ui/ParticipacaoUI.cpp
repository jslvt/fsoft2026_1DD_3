#include "ParticipacaoUI.h"
#include "Menu.h"
#include <iostream>
#include <iomanip>

ParticipacaoUI::ParticipacaoUI(ParticipacaoController& ctrl,
                                PilotoController&       pilotoCtrl,
                                CorridaController&      corridaCtrl)
    : m_ctrl(ctrl), m_pilotoCtrl(pilotoCtrl), m_corridaCtrl(corridaCtrl) {}

void ParticipacaoUI::registarParticipacao() {
    std::cout << "\n=== Registar Participacao ===\n";

    int idPiloto = selecionarPiloto();
    if (idPiloto == 0) { Menu::pausar(); return; }

    int idCorrida = selecionarCorrida();
    if (idCorrida == 0) { Menu::pausar(); return; }

    int   posicao = Menu::lerInt("Posicao Final");
    float tempo   = Menu::lerFloat("Tempo (segundos, ex: 5432.765)");

    if (m_ctrl.registarParticipacao(idPiloto, idCorrida, posicao, tempo))
        std::cout << "  [OK] Participacao registada com sucesso.\n";
    else
        std::cout << "  [ERRO] Nao foi possivel registar a participacao.\n";

    Menu::pausar();
}

void ParticipacaoUI::consultarClassificacao() {
    std::cout << "\n=== Consultar Classificacao ===\n";

    int idCorrida = selecionarCorrida();
    if (idCorrida == 0) { Menu::pausar(); return; }

    Corrida* corrida = m_corridaCtrl.obterPorId(idCorrida);
    auto classificacao = m_ctrl.obterClassificacao(idCorrida);

    std::cout << "\n  Classificacao — " << corrida->getNome()
              << " (" << corrida->getCircuito() << ")\n";
    Menu::separador();

    if (classificacao.empty()) {
        std::cout << "  Sem resultados registados para esta corrida.\n";
    } else {
        std::cout << std::left
                  << std::setw(6)  << "  Pos"
                  << std::setw(32) << "Piloto"
                  << std::setw(14) << "Tempo (s)"
                  << "Pontos\n";
        Menu::separador();
        for (const auto& p : classificacao) {
            Piloto* piloto = m_pilotoCtrl.obterPorId(p.getIdPiloto());
            std::string nomePiloto = piloto ? piloto->getNome() : "(desconhecido)";
            std::cout << std::left
                      << "  " << std::setw(4)  << p.getPosicao()
                      << std::setw(32) << nomePiloto
                      << std::fixed << std::setprecision(3)
                      << std::setw(14) << p.getTempo()
                      << p.getPontos()
                      << "\n";
        }
        Menu::separador();
    }
    Menu::pausar();
}

// ── private ────────────────────────────────────────────────────────────────

int ParticipacaoUI::selecionarPiloto() {
    auto pilotos = m_pilotoCtrl.obterTodos();
    if (pilotos.empty()) {
        std::cout << "  Sem pilotos registados. Crie um piloto primeiro.\n";
        return 0;
    }
    std::cout << "\n  -- Pilotos disponiveis --\n";
    for (const auto& p : pilotos)
        p.print();

    int id = Menu::lerInt("ID do Piloto");
    if (m_pilotoCtrl.obterPorId(id) == nullptr) {
        std::cout << "  [ERRO] Piloto nao encontrado.\n";
        return 0;
    }
    return id;
}

int ParticipacaoUI::selecionarCorrida() {
    auto corridas = m_corridaCtrl.obterTodos();
    if (corridas.empty()) {
        std::cout << "  Sem corridas registadas. Crie uma corrida primeiro.\n";
        return 0;
    }
    std::cout << "\n  -- Corridas disponiveis --\n";
    for (const auto& c : corridas)
        c.print();

    int id = Menu::lerInt("ID da Corrida");
    if (m_corridaCtrl.obterPorId(id) == nullptr) {
        std::cout << "  [ERRO] Corrida nao encontrada.\n";
        return 0;
    }
    return id;
}
