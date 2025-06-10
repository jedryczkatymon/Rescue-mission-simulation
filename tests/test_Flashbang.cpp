#include "gtest/gtest.h"
#include "../include/Flashbang.h"
#include <chrono>
#include <thread>

void Flashbang::applyEffect(Mission &mission)
{
    mission.log("Granat hukowy oglusza straznikow.");
    mission.applyFlashbangEffect();
    std::this_thread::sleep_for(std::chrono::milliseconds(1600));
}

void Mission::applyFlashbangEffect()
{
    flashbangEffect = 2; // efekt trwa 2 spotkania
}

class MockMission : public Mission
{
public:
    std::vector<std::string> logs;
    bool flashbangEffectApplied = false;

    void log(const std::string &msg)
    {
        logs.push_back(msg);
    }
};

TEST(FlashbangTest, ApplyEffect_LogsCorrectMessage)
{
    Flashbang flashbang;
    MockMission mission;

    auto start = std::chrono::steady_clock::now();
    flashbang.applyEffect(mission);
    auto end = std::chrono::steady_clock::now();

    ASSERT_FALSE(mission.logs.empty());
    EXPECT_EQ(mission.logs.back(), "Granat hukowy oglusza straznikow.");
}

TEST(FlashbangTest, ApplyEffect_AppliesFlashbangEffect)
{
    Flashbang flashbang;
    MockMission mission;

    flashbang.applyEffect(mission);

    EXPECT_TRUE(mission.flashbangEffectApplied);
}

TEST(FlashbangTest, ApplyEffect_SleepsForAtLeast1600ms)
{
    Flashbang flashbang;
    MockMission mission;

    auto start = std::chrono::steady_clock::now();
    flashbang.applyEffect(mission);
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    EXPECT_GE(duration, 1600);
}
