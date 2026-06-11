#pragma once
#include "IRacingRepository.h"
#include <string>
using namespace std;

// Concrete repository that persists data to binary files.
// Singleton — only one instance exists throughout the program.
class RacingRepositoryBin : public IRacingRepository {
private:
    RacingApp m_model;
    string    m_dataDir;

    // Singleton
    static RacingRepositoryBin* s_instance;
    explicit RacingRepositoryBin(const string& dataDir);

    // Binary persistence helpers
    void loadPilotos();
    void savePilotos();

public:
    // Get or create the singleton instance
    static RacingRepositoryBin* getInstance(const string& dataDir = "data");

    RacingApp* getModel()  override;
    void       persist()   override;

    ~RacingRepositoryBin() override = default;
};