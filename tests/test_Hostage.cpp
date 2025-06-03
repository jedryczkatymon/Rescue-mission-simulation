#include "gtest/gtest.h"
#include "../include/Hostage.h"

TEST(HostageTest, ConstructorSetsAlive)
{
    Hostage hostage1(true);
    EXPECT_TRUE(hostage1.isAlive());

    Hostage hostage2(false);
    EXPECT_FALSE(hostage2.isAlive());
}

TEST(HostageTest, KillSetsAliveFalse)
{
    Hostage hostage(true);
    hostage.kill();
    EXPECT_FALSE(hostage.isAlive());
}
