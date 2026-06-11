#include <iostream>
#include "RacingRepositoryBin.h"
#include "PilotoService.h"
#include "Controller.h"
using namespace std;

int main() {
    // Repository — singleton, loads data from disk on creation
    RacingRepositoryBin* repo = RacingRepositoryBin::getInstance("data");

    // Services — each receives the repo by pointer
    PilotoService* pilotoService = new PilotoService(repo);

    // Controller — owns the run loop
    Controller controller(pilotoService);
    controller.run();

    cout << "\nAte logo!\n";

    // Cleanup
    delete pilotoService;
    delete repo;

    return 0;
}