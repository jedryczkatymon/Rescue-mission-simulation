#include "Flashbang.h"
#include <thread>

Flashbang::Flashbang() : Item("Granat hukowy") {}

void Flashbang::applyEffect(Mission &mission)
{
    mission.log("Granat hukowy oglusza straznikow.");
    mission.applyFlashbangEffect();
    std::this_thread::sleep_for(std::chrono::milliseconds(1600));
}