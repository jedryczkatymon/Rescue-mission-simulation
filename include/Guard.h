#pragma once
#include "Agent.h"

class Guard : public Agent
{
public:
    Guard(float detectionChance);
    bool detectCommando(float modifier = 1.0f);
    void doSpeak() override;

private:
    float detectionChance;
};
