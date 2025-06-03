#include "Agent.h"

Agent::Agent(bool alive) : alive(alive) {}

bool Agent::isAlive() const {
    return alive;
}

void Agent::kill() {
    alive = false;
}