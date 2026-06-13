#include <iostream>
#include "headers/repo/RacingRepositoryBin.h"
#include "headers/services/PilotoService.h"
#include "headers/services/EquipaService.h"
#include "headers/services/VeiculoService.h"
#include "headers/services/CorridaService.h"
#include "headers/services/ParticipacaoService.h"
#include "headers/controllers/Controller.h"

using namespace std;

int main() {
    RacingRepositoryBin* repo = RacingRepositoryBin::getInstance("data");

    PilotoService*       pilotoService       = new PilotoService(repo);
    EquipaService*       equipaService       = new EquipaService(repo);
    VeiculoService*      veiculoService      = new VeiculoService(repo);
    CorridaService*      corridaService      = new CorridaService(repo);
    ParticipacaoService* participacaoService = new ParticipacaoService(repo);

    Controller controller(pilotoService, equipaService,
                          veiculoService, corridaService,
                          participacaoService);
    controller.run();

    cout << "\nAte logo!\n";

    delete pilotoService;
    delete equipaService;
    delete veiculoService;
    delete corridaService;
    delete participacaoService;
    delete repo;

    return 0;
}
