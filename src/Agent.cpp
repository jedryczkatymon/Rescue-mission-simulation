#include "Agent.h"
#include <iostream>

Agent::Agent(bool alive) : alive(alive) {}

bool Agent::isAlive() const
{
    return alive;
}

void Agent::kill()
{
    alive = false;
}

void Agent::doSpeak()
{
    std::cout << "[Agent] Czysto!\n";
}