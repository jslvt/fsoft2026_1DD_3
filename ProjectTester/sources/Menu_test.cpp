#include <iostream>
#include "../headers/PilotoUI_test.h"

using namespace std;

void menu(int& opcao) {
    cout << "------MENU------" << endl;
    cout << "1. Piloto" << endl;
    cout << "2. Equipa" << endl;
    cout << "3. Veiculo" << endl;
    cout << "4. Corrida" << endl;
    cout << "5. Participacao" << endl;
    cout << "6. Sair" << endl;
    cin >> opcao;
    switch (opcao) {
        default:
            break;
        case 1:
            cout << "1. Criar piloto" << endl;
            cout << "2. Listar pilotos" << endl;
            cout << "3. Voltar atras" << endl;
            cin >> opcao;
            if (opcao == 1) {
                criarPiloto();
            }
            else if (opcao == 2) {
                listarPilotos();
            }
            else {

            }
            break;
        case 2:
            cout<<"Opcao 2"<<endl;
            break;
        case 3:
            cout<<"Opcao 3"<<endl;
            break;
        case 4:
            cout<<"Opcao 4"<<endl;
            break;
        case 5:
            cout<<"Opcao 5"<<endl;
            break;
        case 6:
            cout<<"Xau!"<<endl;
            break;
    }
}