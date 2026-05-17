#include <iostream>
#include <filesystem>

#include "ui/Menu.h"
#include "ui/PilotoUI.h"
#include "ui/EquipaUI.h"
#include "ui/VeiculoUI.h"
#include "ui/CorridaUI.h"
#include "ui/ParticipacaoUI.h"

#include "controller/PilotoController.h"
#include "controller/EquipaController.h"
#include "controller/VeiculoController.h"
#include "controller/CorridaController.h"
#include "controller/ParticipacaoController.h"

// ── helpers ────────────────────────────────────────────────────────────────

static void menuPilotos(PilotoUI& ui) {
    int op;
    do {
        op = Menu::mostrarMenu("Pilotos",
            {"Criar Piloto", "Listar Pilotos", "Voltar"});
        if (op == 1) ui.criarPiloto();
        if (op == 2) ui.listarPilotos();
    } while (op != 3);
}

static void menuEquipas(EquipaUI& ui) {
    int op;
    do {
        op = Menu::mostrarMenu("Equipas",
            {"Criar Equipa", "Listar Equipas", "Voltar"});
        if (op == 1) ui.criarEquipa();
        if (op == 2) ui.listarEquipas();
    } while (op != 3);
}

static void menuVeiculos(VeiculoUI& ui) {
    int op;
    do {
        op = Menu::mostrarMenu("Veículos",
            {"Criar Veiculo", "Listar Veiculos", "Voltar"});
        if (op == 1) ui.criarVeiculo();
        if (op == 2) ui.listarVeiculos();
    } while (op != 3);
}

static void menuCorridas(CorridaUI& ui) {
    int op;
    do {
        op = Menu::mostrarMenu("Corridas",
            {"Criar Corrida", "Listar Corridas", "Voltar"});
        if (op == 1) ui.criarCorrida();
        if (op == 2) ui.listarCorridas();
    } while (op != 3);
}

static void menuParticipacoes(ParticipacaoUI& ui) {
    int op;
    do {
        op = Menu::mostrarMenu("Participacoes",
            {"Registar Participação", "Consultar Classificação", "Voltar"});
        if (op == 1) ui.registarParticipacao();
        if (op == 2) ui.consultarClassificacao();
    } while (op != 3);
}

// ── main ───────────────────────────────────────────────────────────────────

int main() {
    // Ensure data/ folder exists relative to the executable working directory
    std::filesystem::create_directories("data");

    // ── Controllers (own the data + persistence) ───────────────────────────
    PilotoController    pilotoCtrl  ("data/pilotos.bin");
    EquipaController    equipaCtrl  ("data/equipas.bin");
    VeiculoController   veiculoCtrl ("data/veiculos.bin");
    CorridaController   corridaCtrl ("data/corridas.bin");
    ParticipacaoController participacaoCtrl(
        "data/participacoes.bin", pilotoCtrl, corridaCtrl);

    // ── UI objects (reference controllers) ────────────────────────────────
    PilotoUI       pilotoUI      (pilotoCtrl);
    EquipaUI       equipaUI      (equipaCtrl);
    VeiculoUI      veiculoUI     (veiculoCtrl);
    CorridaUI      corridaUI     (corridaCtrl);
    ParticipacaoUI participacaoUI(participacaoCtrl, pilotoCtrl, corridaCtrl);

    // ── Main loop ─────────────────────────────────────────────────────────
    int op;
    do {
        op = Menu::mostrarMenu(
            "Sistema de Gestão de Pilotos de Automobilismo",
            {
                "Pilotos",
                "Equipas",
                "Veículos",
                "Corridas",
                "Participações",
                "Sair"
            });
        switch (op) {
            case 1: menuPilotos      (pilotoUI);       break;
            case 2: menuEquipas      (equipaUI);       break;
            case 3: menuVeiculos     (veiculoUI);      break;
            case 4: menuCorridas     (corridaUI);      break;
            case 5: menuParticipacoes(participacaoUI); break;
            default: break;
        }
    } while (op != 6);

    std::cout << "\n  Até logo!\n\n";
    return 0;
}
