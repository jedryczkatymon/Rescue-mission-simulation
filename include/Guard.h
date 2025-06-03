#pragma once
#include "Agent.h"

class Guard : public Agent {
public:
    Guard(float detectionChance);
    bool detectCommando() const;

private:
    float detectionChance;
};
