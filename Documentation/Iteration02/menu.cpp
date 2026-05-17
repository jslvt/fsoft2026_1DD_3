#include <iostream>

#include "Menu.h"
#include "PilotoUI.h"
#include "EquipaUI.h"
#include "VeiculoUI.h"
#include "CorridaUI.h"
#include "ParticipacaoUI.h"

using namespace std;

void Menu::mostrarMenu() {

    PilotoUI pilotoUI;
    EquipaUI equipaUI;
    VeiculoUI veiculoUI;
    CorridaUI corridaUI;
    ParticipacaoUI participacaoUI;

    int opcao;

    do {

        cout << "\n====== GESTAO AUTOMOBILISMO ======\n";
        cout << "1 - Pilotos\n";
        cout << "2 - Equipas\n";
        cout << "3 - Veiculos\n";
        cout << "4 - Corridas\n";
        cout << "5 - Participacoes\n";
        cout << "0 - Sair\n";

        opcao = lerOpcao();

        switch(opcao) {

            case 1:
                pilotoUI.listarPilotos();
                break;

            case 2:
                equipaUI.listarEquipas();
                break;

            case 3:
                veiculoUI.listarVeiculos();
                break;

            case 4:
                corridaUI.listarCorridas();
                break;

            case 5:
                participacaoUI.consultarClassificacao();
                break;

            case 0:
                cout << "\nPrograma terminado.\n";
                break;

            default:
                cout << "\nOpcao invalida.\n";
        }

    } while(opcao != 0);
}

int Menu::lerOpcao() {

    int opcao;

    cout << "\nOpcao: ";
    cin >> opcao;

    return opcao;
}