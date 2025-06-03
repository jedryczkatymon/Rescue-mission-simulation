#include "Mission.h"
#include "Logger.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <algorithm>
#include <random>
#include <chrono>
#include <filesystem>
#include "Smoke.h"
#include "Flashbang.h"
#include "Silencer.h"

// Konstruktor misji – inicjalizacja strażników, zakładników i ekwipunku
Mission::Mission() : rng(std::random_device{}())
{ // inicjalizacja rng

    std::uniform_real_distribution<float> detectionDist(0.10f, 0.19f);

    // Tworzenie 6 strażników z losową szansą wykrycia komandosa
    for (int i = 0; i < 6; ++i)
    {
        guards.emplace_back(detectionDist(rng));
    }

    // Dodanie dwóch zakładników
    hostages.emplace_back();
    hostages.emplace_back();

    // Dodanie przedmiotów do ekwipunku komandosa
    commando.addItem(std::make_unique<SmokeGrenade>());
    commando.addItem(std::make_unique<Flashbang>());
    commando.addItem(std::make_unique<Silencer>());
}

void Mission::log(const std::string &message)
{
    logEntries.push_back(message);
}

void Mission::run()
{
    startTime = std::chrono::high_resolution_clock::now();
    simulate();
    endTime = std::chrono::high_resolution_clock::now();
    logToCSV();
}

void Mission::simulate()
{
    logEntries.clear();
    logEntries.push_back("Tworzenie misji...");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    logEntries.push_back("Misja rozpoczęta.");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    logEntries.push_back("Komandos skrada się.");
    std::this_thread::sleep_for(std::chrono::milliseconds(rng() % 1000 + 500));

    bool missionFailed = false;

    simulateGuardEncounters(missionFailed);

    if (!missionFailed)
    {
        rescueHostages();
        missionSuccess = true;
    }
    else
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        logEntries.push_back("Komandos został zauważony. Misja zakończona niepowodzeniem.");
        missionSuccess = false;
    }
}

void Mission::applyFlashbangEffect()
{
    flashbangEffect = 2; // efekt trwa 2 spotkania
}
void Mission::applySmokeEffect()
{
    smokeEffect = 2; // efekt trwa 2 spotkania
}
int Mission::getFlashbangEffect() const
{
    return flashbangEffect;
}
int Mission::getSmokeEffect() const
{
    return smokeEffect;
}

void Mission::simulateGuardEncounters(bool &missionFailed)
{
    std::vector<size_t> guardIndices(guards.size());
    for (size_t i = 0; i < guards.size(); ++i)
    {
        guardIndices[i] = i;
    }
    std::shuffle(guardIndices.begin(), guardIndices.end(), rng);

    std::uniform_int_distribution<int> killRollDist(0, 99);
    std::uniform_int_distribution<int> useItemDist(0, 1);
    std::uniform_int_distribution<int> sleepDist(500, 1500);

    for (size_t idx : guardIndices)
    {
        if (!guards[idx].isAlive())
            continue;
        float detectionModifier = 1.0f;
        if (flashbangEffect > 0)
            detectionModifier *= 0.5f; // zmniejsz o 50%
        if (smokeEffect > 0)
            detectionModifier *= 0.7f; // zmniejsz o 30%

        if (guards[idx].detectCommando(detectionModifier))
        {
            logEntries.push_back("[Strażnik nr " + std::to_string(idx + 1) + "] wykrył komandosa! Alarm! Misja zakończona.");
            missionFailed = true;
            break;
        }

        if (flashbangEffect > 0)
            --flashbangEffect;
        if (smokeEffect > 0)
            --smokeEffect;

        if (guards[idx].detectCommando())
        {
            logEntries.push_back("[Strażnik nr " + std::to_string(idx + 1) + "] wykrył komandosa! Alarm! Misja zakończona.");
            missionFailed = true;
            break;
        }

        int killRoll = killRollDist(rng);
        int killThreshold = hasSilencer ? 80 : 50;

        if (killRoll < killThreshold)
        {
            guards[idx].kill();
            logEntries.push_back("Komandos eliminuje strażnika nr " + std::to_string(idx + 1) + ".");
            killedGuards++;
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepDist(rng)));
            logEntries.push_back("Komandos znów się skrada.");
        }

        // Próba użycia przedmiotu
        for (auto &itemPtr : commando.getItems())
        {
            if (!itemPtr->isUsed() && useItemDist(rng) != 0)
            { // 50% szansy
                itemPtr->use();
                logEntries.push_back("Komandos używa narzędzia: " + itemPtr->getName());

                itemPtr->applyEffect(*this);

                break; // używamy tylko jeden przedmiot naraz
            }
        }
    }
}

void Mission::rescueHostages()
{
    for (auto &hostage : hostages)
    {
        hostage.rescue();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(rng() % 2000 + 1000));
    logEntries.push_back("Zakładnicy uratowani.");
    logEntries.push_back("Komandos niezauważony. Misja zakończona sukcesem.");
}

void Mission::logResults() const
{
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    int total_ms = static_cast<int>(duration.count());

    int minutes = total_ms / 60000;
    int seconds = (total_ms % 60000) / 1000;
    int milliseconds = (total_ms % 1000) / 10;

    std::cout << "Czas misji: "
              << std::setw(2) << std::setfill('0') << minutes << ":"
              << std::setw(2) << std::setfill('0') << seconds << ":"
              << std::setw(2) << std::setfill('0') << milliseconds << "\n";

    std::cout << "Status misji: " << (missionSuccess ? "SUKCES" : "NIEPOWODZENIE") << "\n";
    std::cout << "Zabici strażnicy: " << killedGuards << "\n";
    std::cout << "Żywi strażnicy: " << (guards.size() - killedGuards) << "\n";

    int unusedItems = 0;
    for (const auto &itemPtr : commando.getItems())
    {
        if (!itemPtr->isUsed())
            unusedItems++;
    }
    std::cout << "Nie użyte przedmioty: " << unusedItems << "\n";

    std::cout << "\n=== LOG MISJI ===\n";
    for (const auto &entry : logEntries)
    {
        std::cout << entry << "\n";
    }
}

void Mission::logToCSV() const
{
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

    int unusedItems = 0;
    for (const auto &itemPtr : commando.getItems())
    {
        if (!itemPtr->isUsed())
            unusedItems++;
    }

    std::filesystem::create_directories("logs");

    std::ostringstream logStream;
    logStream << duration.count() << "s,";
    logStream << (missionSuccess ? "Success" : "Fail") << ",";
    logStream << killedGuards << ",";
    logStream << (guards.size() - killedGuards) << ",";
    logStream << unusedItems << ",";

    for (const auto &log : logEntries)
    {
        logStream << log << "   ";
    }

    Logger::writeCSV("logs/mission_log.csv", logStream.str());
}
