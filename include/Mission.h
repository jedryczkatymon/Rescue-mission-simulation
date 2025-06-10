#pragma once
#include <vector>
#include <chrono>
#include <random>
#include "Commando.h"
#include "Guard.h"
#include "Hostage.h"

class Mission {
public:
    Mission();
    void run();
    void logResults() const;
    void setHasSilencer(bool value) { hasSilencer = value; }
    bool getHasSilencer() const { return hasSilencer; }
    virtual void log(const std::string& message);
    void applyFlashbangEffect();
    void applySmokeEffect();
    int getFlashbangEffect() const;
    int getSmokeEffect() const;

private:
    Commando commando;
    std::vector<Guard> guards;
    std::vector<Hostage> hostages;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
    std::vector<std::string> logEntries;
    bool missionSuccess = false;
    int killedGuards = 0;
    bool hasSilencer = false;
    int flashbangEffect = 0;
    int smokeEffect = 0;

    std::mt19937 rng;

    void simulate();
    void simulateGuardEncounters(bool& missionFailed);
    void simulateItemUsage();
    void rescueHostages();

    void logToCSV() const;
};
