#include <iostream>
#include "RacingRepositoryBin.h"
#include "PilotoService.h"
#include "EquipaService.h"
#include "VeiculoService.h"
#include "Controller.h"
using namespace std;

int main() {
    RacingRepositoryBin* repo = RacingRepositoryBin::getInstance("data");

    PilotoService*  pilotoService  = new PilotoService(repo);
    EquipaService*  equipaService  = new EquipaService(repo);
    VeiculoService* veiculoService = new VeiculoService(repo);

    Controller controller(pilotoService, equipaService, veiculoService);
    controller.run();

    cout << "\nAte logo!\n";

    delete pilotoService;
    delete equipaService;
    delete veiculoService;
    delete repo;

    return 0;
}
