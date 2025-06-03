#include "Guard.h"
#include <random>
#include <cassert>

Guard::Guard(float detectionChance)
    : Agent(true), detectionChance(detectionChance) {
    assert(detectionChance >= 0.0f && detectionChance <= 1.0f);
}

bool Guard::detectCommando() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);
    float roll = dist(gen);
    return alive && (roll < detectionChance);
}
