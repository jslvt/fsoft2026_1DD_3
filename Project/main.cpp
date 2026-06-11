#include <iostream>
#include "RacingRepositoryBin.h"
#include "PilotoService.h"
#include "EquipaService.h"
#include "Controller.h"
using namespace std;

int main() {
    RacingRepositoryBin* repo = RacingRepositoryBin::getInstance("data");

    PilotoService* pilotoService = new PilotoService(repo);
    EquipaService* equipaService = new EquipaService(repo);

    Controller controller(pilotoService, equipaService);
    controller.run();

    cout << "\nAte logo!\n";

    delete pilotoService;
    delete equipaService;
    delete repo;

    return 0;
}