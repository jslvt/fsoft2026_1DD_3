#pragma once
#include "IRacingRepository.h"
#include <string>
using namespace std;

class RacingRepositoryBin : public IRacingRepository {
private:
    RacingApp m_model;
    string    m_dataDir;

    static RacingRepositoryBin* s_instance;
    explicit RacingRepositoryBin(const string& dataDir);

    void loadPilotos();
    void savePilotos();
    void loadEquipas();
    void saveEquipas();

public:
    static RacingRepositoryBin* getInstance(const string& dataDir = "data");

    RacingApp* getModel()  override;
    void       persist()   override;

    ~RacingRepositoryBin() override = default;
};
