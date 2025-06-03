#include "gtest/gtest.h"
#include "../include/Mission.h"

TEST(MissionTest, ConstructorInitializesState)
{
    Mission mission;
    EXPECT_FALSE(mission.isCompleted());
}

TEST(MissionTest, StartChangesState)
{
    Mission mission;
    mission.start();
    EXPECT_TRUE(mission.isStarted());
}

