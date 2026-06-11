#pragma once
#include "RacingApp.h"

// Interface for the repository.
// Any concrete implementation (memory, binary files, database)
// must implement getModel() and persist().
class IRacingRepository {
public:
    virtual RacingApp* getModel()  = 0;
    virtual void       persist()   = 0;
    virtual ~IRacingRepository()   = default;
};