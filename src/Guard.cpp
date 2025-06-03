#include "Guard.h"
#include <random>
#include <cassert>

Guard::Guard(float detectionChance)
    : Agent(true), detectionChance(detectionChance)
{
    assert(detectionChance >= 0.0f && detectionChance <= 1.0f);
}

bool Guard::detectCommando(float modifier)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);
    float roll = dist(gen);
    float effectiveChance = detectionChance * modifier;
    if (effectiveChance > 1.0f) effectiveChance = 1.0f;
    if (effectiveChance < 0.0f) effectiveChance = 0.0f;
    return alive && (roll < effectiveChance);
}
