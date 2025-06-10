#include "gtest/gtest.h"
#include "../include/Guard.h"
#include <sstream>
#include <iostream>
#include "Guard.h"
#include <random>
#include <cassert>
#include <iostream>

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
    if (effectiveChance > 1.0f)
        effectiveChance = 1.0f;
    if (effectiveChance < 0.0f)
        effectiveChance = 0.0f;
    return alive && (roll < effectiveChance);
}

void Guard::doSpeak()
{
    std::cout << "[Guard] Kto tam?!\n";
}

TEST(GuardTest, ConstructorSetsAlive)
{
    Guard guard1(0.5f);
    EXPECT_TRUE(guard1.isAlive());
}

TEST(GuardTest, KillSetsAliveFalse)
{
    Guard guard(0.5f);
    guard.kill();
    EXPECT_FALSE(guard.isAlive());
}

TEST(GuardTest, ConstructorDetectionChanceValidRange)
{
    EXPECT_NO_THROW(Guard guard(0.0f));
    EXPECT_NO_THROW(Guard guard(1.0f));
    EXPECT_NO_THROW(Guard guard(0.5f));
}

TEST(GuardTest, DetectCommandoAlwaysDetectsIfChanceOne)
{
    Guard guard(1.0f);
    bool detected = false;
    for (int i = 0; i < 100; ++i) {
        if (guard.detectCommando(1.0f)) {
            detected = true;
            break;
        }
    }
    EXPECT_TRUE(detected);
}

TEST(GuardTest, DetectCommandoNeverDetectsIfChanceZero)
{
    Guard guard(0.0f);
    bool detected = false;
    for (int i = 0; i < 100; ++i) {
        if (guard.detectCommando(1.0f)) {
            detected = true;
            break;
        }
    }
    EXPECT_FALSE(detected);
}

TEST(GuardTest, DetectCommandoModifierLimits)
{
    Guard guard(0.5f);
    bool detected = false;
    for (int i = 0; i < 100; ++i) {
        if (guard.detectCommando(3.0f)) {
            detected = true;
            break;
        }
    }
    EXPECT_TRUE(detected);

    detected = false;
    for (int i = 0; i < 100; ++i) {
        if (guard.detectCommando(-1.0f)) {
            detected = true;
            break;
        }
    }
    EXPECT_FALSE(detected);
}

TEST(GuardTest, DetectCommandoReturnsFalseIfDead)
{
    Guard guard(1.0f);
    guard.kill();
    EXPECT_FALSE(guard.detectCommando(1.0f));
}

TEST(GuardTest, DoSpeakOutputsCorrectString)
{
    Guard guard(0.5f);
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    guard.doSpeak();
    std::cout.rdbuf(oldCout);
    EXPECT_EQ(buffer.str(), "[Guard] Kto tam?!\n");
}
