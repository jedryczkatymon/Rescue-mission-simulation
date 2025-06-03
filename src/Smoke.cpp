#include "Smoke.h"
#include <thread>

SmokeGrenade::SmokeGrenade() : Item("Granat dymny") {}

void SmokeGrenade::applyEffect(Mission &mission)
{
    mission.log("Granat dymny oslepia straznikow w poblizu.");
    mission.applySmokeEffect();
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
}